---
title: " DTOJ1992购票\t\t"
tags:
  - CDQ分治
  - dp
  - 凸包
  - 斜率dp
  - 点分治
  - 线段树
url: 3500.html
id: 3500
categories:
  - Solution
date: 2018-08-18 11:39:26
---

神仙。

首先我们先想一个相对暴力的做法。设$f\[i\]$为$i$的最优答案，那么显然有

$$f\[i\]=\\min\_j^{deep\[i\]-deep\[j\] \\leq L\_i} \\{f\[j\]+(deep\[i\]-deep\[j\])·p\_i \\} +q\_i$$

然后我们愉快的获得了一个$O(n^2)$做法。

但是那个限制十分讨厌。我们考虑先去掉限制与树，即$t=0$的情况。那么可以发现，当前位置为$i$,假设存在$k<j$且$j$比$k$优，那么会有

$$f\[j\]-deep\[j\] \\times p\_i<f\[k\]-deep\[k\] times p\_i$$

很明显可以斜率优化做过去。

到了树上，并加上限制，就是要我们动态维护凸包。

我们把树直接树链剖分之后，对应的满足条件的是dfs序上的多段区间。所以我们用线段树暴力维护凸包，每个节点开一个vector然后暴力维护这段区间的凸包。

每次询问复杂度是$O(n \ log^2 n )$的。

还有CDQ分治+点分治+斜率优化dp的做法。