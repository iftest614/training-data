---
title: " DTOJ3504送你一堆区间xmasinterval\t\t"
tags:
  - dp
url: 280.html
id: 280
categories:
  - DTOJ
  - Solution
date: 2018-01-18 19:30:20
---

显然没有关键点的位置没有用，于是我们可以按照关键点的位置把区间离散，变成这段区间能覆盖的关键点区间。 考虑$dp$，$f\[i\]$表示前$i$个关键点完全覆盖的方案数。 对于一个能覆盖$\[l,r\]$关键点的区间，它能使$f\[r\]$多出$\\sum_{i=l-1}^{r}f\[i-1\]$种方案。并且能使$f\[i\](i\\in\[r,m\])$方案数$\\times 2$。 按区间左端点从小到达排序，按顺序$dp$即可。 注意特判一个关键点都不能覆盖的区间对答案的影响。