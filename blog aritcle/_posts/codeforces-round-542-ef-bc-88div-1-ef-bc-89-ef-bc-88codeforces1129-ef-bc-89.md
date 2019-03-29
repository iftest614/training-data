---
title: " Codeforces Round #542 (Div. 1)（Codeforces1129）\t\t"
tags:
  - dp
  - 分块
  - 思路
  - 构造
url: 6914.html
id: 6914
categories:
  - Codeforces
  - Solution
date: 2019-03-10 13:41:22
---

[A:Toy Train](https://codeforces.com/contest/1129/problem/A2)
-------------------------------------------------------------

### 题意

有$n$个站按顺序围成一个圆，有$m$个糖果，第$i$个要从$a\_i$运到$b\_i$。有一辆火车，只能从第$i$个站到第$i\\% n+1$个站。到一个站时，只能将一个糖果放上车，可以放下多个糖果。 对于每个$i\\in\[1,n\]$，求火车从第$i$个站出发，最少要走多少路程才能送完所有糖果。

### 题解

如果一个站有$x$个糖果要出发，那么火车肯定得经过这个站至少$x$次，也就是至少绕$x-1$圈。 那么我们只要考虑最后未绕完的那圈在哪里停止即可。 对于每个$i$都暴力跑一边求答案。 时间复杂度$\\Theta(nm)$。 出题人有更优解法。  

[B:Wrong Answer](https://codeforces.com/contest/1129/problem/B)
---------------------------------------------------------------

### 题意

定义一个长度为$m$的序列的价值为$m\\sum_{i=1}^{m}a_i$。 某人写了一个计算长度为$n$的序列中价值最大的连续子序列的价值，如下

function find_answer(n, a)
    # Assumes n is an integer between 1 and 2000, inclusive
    # Assumes a is a list containing n integers: a\[0\], a\[1\], ..., a\[n-1\]
    res = 0
    cur = 0
    k = -1
    for i = 0 to i = n-1
        cur = cur + a\[i\]
        if cur < 0
            cur = 0
            k = i
        res = max(res, (i-k)*cur)
    return res

显然这是错的。 给定一个$k$，请你构造出一个序列使得他的答案和正确答案恰好差$k$。

### 题解

我他妈将价值看成$\\sum_{i=1}^{m}i\\cdot a_i$，然后WA test 1一脸懵逼。 我们可以构造一个形如$0 \\space 0\\space 0\\space …\\space 0 -a b$的序列。 记前面有$len-2$个$0$，那么他的答案是$b$，正确答案是$len(b-a)$。 也就说我们要求$a,b,len$，满足 $$len(b-a)-b=k$$ 由于$len\\leq 2000$，我们可以暴力枚举$len$。 然后取$b-a=\\left \\lceil \\frac{k-1}{len}\\right \\rceil$，然后通过等式计算出$b$，然后也可以知道$a$。 如果$a>0,b>0$就是合法解。 发现在$k$较大的时候构造不出来，因为这样求出来的$b$是$<len$的。我们可以不断让$b$加上$len$，同时$b-a$加$1$，直到$a>0,b>0$或者$b>10^6$。 这样就可以构造出所有情况了。  

[C:Morse Code](https://codeforces.com/contest/1129/problem/C)
-------------------------------------------------------------

### 题意

长度为$1\\sim 4$的$01$字符串除了$0011,0101,1110,1111$剩下的$26$个分别对应着$26$个大写字母。 给你一个$01$字符串$S$，对于$S$的每个前缀求出用这个前缀的子串能表示出多少种大写字母串。

### 题解

考虑每次新增一个前缀，这个前缀的每个后缀能表示出多少个大写字母串。 记$f\[i\]$为第$i$个后缀能表示出的大写字母串的数量。 容易想到$f\[i\]=f\[i+1\]+f\[i+2\]+f\[i+3\]+f\[i+4\]$。 但是如果$\[i,i+3\]$对应的$01$串是不合法的那$4$个，就不能加上$f\[i+4\]$。 如果第$i$个后缀之前没有出现过，就将$f\[i\]$加入答案。 判断一个字符串有没有出现过要手写hash表，用map会TLE。 时间复杂度$\\Theta(n^2)$。  

[D:Isolation](https://codeforces.com/contest/1129/problem/D)
------------------------------------------------------------

### 题意

将长度为$n$的序列分段，使得每段中只出现一次的数不超过$k$个。求方案数。

### 题解

考虑dp。 记$f\[i\]$为将前$i$个数分段的方案数。 那么有 $$ f\[i\]=\\sum_{j=1}^{i}\[cnt(j,i)\\leq k\]f\[j-1\] $$ $cnt(j,i)$表示区间$\[j,i\]$中只出现过一次的数的个数。 这样是$\\Theta(n^2)$的，考虑优化。 对于同一个$j$，$cnt(j,i)$和$cnt(j,i+1)$的差只有$\\pm 1$。并且，$+1$的$j$是连续的一段，$-1$的$j$也是连续的一段。 考虑分块。 每一块中，我们维护对于当前的$i$，$cnt(j,i)=s$的$f\[j\]$的和，记为$Sum\_s$。 对于区间$cnt$的$\\pm 1$，整块的我们打标记。记第$x$块的标记为$tag\_x$，所以实际上第$x$块的$Sum\_s$实际上是$cnt(j,i)=s+tag\_x$的$f\[j\]$的和。 考虑$tag\_x$变化时对$f\[i\]$的影响，显然只有$s+tag\_x=k$这个边界才会对答案有影响，利用$Sum_s$更新一下对$f\[i\]$的贡献即可。 零散块的我们直接暴力修改对$Sum$和对$f\[i\]$的影响即可。  

[E:Legendary Tree](https://codeforces.com/contest/1129/problem/E)
-----------------------------------------------------------------

（没写，留坑，可能以后会写）

### 题意

### 题解