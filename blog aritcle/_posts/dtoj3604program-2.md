---
title: " DTOJ3604program\t\t"
tags:
  - 无标签
url: 1948.html
id: 1948
categories:
  - Solution
date: 2018-05-11 17:11:12
---

我们可以发现，对于一段的操作，全部完成的时间一定是处于一个子段中的。那么我们可以求出一段程序的开始时间和结束时间，前缀和相减以后就可以得到这段区间的答案了。 那么我们考虑如何得到一个时间点上的答案。 设$f\_i$为指针第一次从$i-1$与移动到$i$的时间，$g\_i$为指针第一次从$i$移动到$i-1$的时间。这个可以用链表模拟来得到答案。那么区间$\[l,r\]$运行的开始时间是$f\_l$,结束时间是$min\\{f\_{r+1},g_l\\}$。