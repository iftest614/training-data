---
title: " DTOJ2518EL_BSGS的区间\t\t"
tags:
  - dp
  - 奇技淫巧
url: 5078.html
id: 5078
categories:
  - Solution
date: 2018-11-13 16:12:55
---

这是什么shi题...

首先可以知道的是，答案是可以二分的。那么对于二分出的答案，我们直接对于每次选取减去答案$ans$，假设最后和为$0$才是合法的，这个性质十分显然，因为选取$k$次之后答案也会被减去$k$次$ans$，和大等$0$才是合法的解。

考虑最优化策略。绝对值这个很难处理。$f\[l\]\[r\]$为$\[l,r\]$中最多还有一个未完成区间，其他区间已经完成， 当前未完成区间贡献为正的最大收益。$g\[l\]\[r\]$为$\[l,r\]$中最多还有一个未完成区间，其他区间已经完成，当前未完成区间贡献为负，其他已完成区间贡献取负的最小收益。这个东西为什么是正确的，因为为了化掉绝对值的限制，我们将这个东西变成$\\max(x,-x)$的形式。那么我们对这个取最大就可以取掉绝对值的限制了。

那么转移的时候我们用区间dp的技巧枚举$\[l,r\]$，固定左边的$l$，然后枚举中间分隔点转移。因为一段区间合在一起，一定是取正或者取负，那么我们枚举让其在左边取正，右边取负，然后合并两边的区间，强行让未完成区间合并。可以发现的是这时候，我们就是强行取到了可以取的最大值了。

需要注意的是，在$g\[l\]\[r\]$的转移中，最后需要的是加上$A\[l\]$。因为在这里我们是强制让$A\[l\]$未完成，而未完成的部分在上面是仍然以正着的计算的，否则转移起来就是错的。

具体细节请食用代码。

    #include<bits/stdc++.h>
    #define N 205
    #define db double
    int n, A[N];
    db f[N][N], g[N][N];
    bool check (db x)
    {
        for (int i = 1; i <= n; i++) f[i][i] = g[i][i] = A[i];
        for (int len = 1; len < n; len++)
            for (int l = 1; l + len <= n; l++)
            {
                int r = l + len;
                f[l][r] = f[l + 1][r], g[l][r] = g[l + 1][r];
                for (int j = l + 1; j <= r; j++)
                    f[l][r] = std::max (f[l][r], f[j + 1][r] - g[l + 1][j] - x),
                    g[l][r] = std::min (g[l][r], g[j + 1][r] - f[l + 1][j] + x);
                f[l][r] += A[l], g[l][r] += A[l];
            }
        return std::max (f[1][n], -g[1][n]) >= x;
    }
    int main ()
    {
        db l = 0, r = 0, mid;
        scanf ("%d", &n);
        for (int i = 1; i <= n; i++) scanf ("%d", &A[i]), r += abs(A[i]);
        while (r - l > 1e-7)
        {
            mid = (l + r) / 2;
            if (check (mid)) l = mid;
            else r = mid;
        }
        printf ("%.4lf\n", l);
    }