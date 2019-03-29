---
title: " DTOJ3510Permutation\t\t"
tags:
  - dp
url: 344.html
id: 344
categories:
  - DTOJ
  - Solution
date: 2018-01-21 14:44:19
---

先把已经固定的边连起来，判掉初始不合法的情况。现在的图由一些独立点，一些环和一些链组成。 环的形态已经固定了，所以我们只考虑点和链。 将链按照点数分为奇链和偶链，显然奇链的作用和一个点是一样的，我们就可以把奇链当做点。 现在考虑有$i$个独立点有多少种合法的方案，记为$f\[i\]$。

$f\[i\]=\\sum_{j=2,j为偶数}^{i}C_{i-1}^{j-1}\\times (j-1)!\\times f\[i-j\]$

即枚举第$i$个点所在环的大小计算方案，其中$(j-1)!$是$j$个点组成环的方案数。将组合数拆开，那么有

$f\[i\]=\\sum_{j=2,j为偶数}^{i}\\frac{(i-1)!}{(j-1)!(i-j)!}\\times (j-1)!\\times f\[i-j\]$

$f\[i\]=\\sum_{j=0,j为偶数}^{i}\\frac{(i-1)!}{(i-j)!}\\times f\[i-j\]$

发现一个$j$对后面所有的$i$的贡献都是一样的，令$Sum\[i\]=\\sum_{j=2,j为偶数}^{i}\\frac{f\[j\]}{j!}$。 于是就有

$f\[i\]=(i-1)!\\times Sum\[i-2\]$

其实找规律发现这个式子化简完应该是$f\[i\]=\\prod_{j=1,j为奇数}^{j<i}j^2$。 现在我们考虑偶链对答案的影响。 假如除偶链外有$n$个点（一条奇链算一个点），第一条偶链可以选择插在任意一个环的任意位置，这有$n$种情况；或者自己向自己连一条边构成一个偶环。 因此共有$n+1$种情况，方案数应$\\times (n+1)$。现在图中有$n+1$个点（偶链形态固定，只能算一个点），剩下的偶链在新图的基础上继续算对答案造成的影响即可。