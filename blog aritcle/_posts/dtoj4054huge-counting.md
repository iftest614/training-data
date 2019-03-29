---
title: " DTOJ4054Huge Counting\t\t"
tags:
  - 奇技淫巧
  - 容斥
  - 数位dp
  - 数学
url: 5358.html
id: 5358
categories:
  - DTOJ
  - Solution
date: 2018-12-07 21:40:06
---

$f(x\_1,x\_2,…,x\_k)$的值相当于我们从$(1,1,…,1)$出发，每次使得某一维坐标$+1$，走到$(x\_1,x\_2,…,x\_k)$的方案数$\\%2$。 不妨让所有的$x\_i$都$-1$。 我们根据二维的情况拓展一下，方案数就是 $$\\prod\_{i=1}^{k-1}\\binom{\\sum_{j=i}^{k}x\_j}{x\_i}$$ 由于交换坐标方案数不变，因此$\\binom{x\_i+x\_j}{x\_i},1\\leq i\\neq j\\leq k$一定是方案数的因子。 因此如果方案数为奇数，就要求所有的$\\binom{x\_i+x\_j}{x\_i}\\%2=1$。 通过Lucas定理我们可以知道，$\\binom{n}{m}$的充要条件是$n\\&m=m$。 也就是说，$f(x)=1$的必要条件是对于任意$1\\leq i\\neq j\\leq k$，有$(x\_i+x\_j)\\&x\_i=x\_i$。 可以证明这个条件也是充分的，但是我不会。题解里是这么说的： ![](http://www.dtenomde.com/wp-content/uploads/2018/12/D124FA4A-088B-4925-9D61-4374B37EA4C7.jpg) 换句话说，对于每一个二进制位，至多只能有一个$x\_i$这位为$1$。 我们先考虑所有$l\_i=1$的情况。这很明显是个数位dp。 我们记$f\[i\]\[j\]$为当前考虑到第$i$位（从高到低），每一维的前$i$位顶到上界的状态为$j$。 枚举当前位的$1$放在哪维或者不放即可转移。 对于$l_i\\neq 1$的情况，我们简单容斥一下即可。