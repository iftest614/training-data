---
title: " DTOJ2399Tasty Dishes\t\t"
tags:
  - 分治
url: 984.html
id: 984
categories:
  - DTOJ
  - Solution
date: 2018-03-09 22:00:15
---

很容易有枚举一个端点，再找另一个端点的想法，但这样好像不可以做。 考虑分治。和最小值最大值有关的找区间问题好像很多都可以用分治做，分治真是神奇。 考虑在$\[l,r\]$中跨过$mid$的区间。 先枚举最小值在左半段的情况。也就是区间左端点不断往左推，每推一个位置右端点向右拓到最大。同时存下每个合法的右半段的和的个数，然后就可以通过当前左半段的和来计算区间个数。 同样再做一遍最小值在右半段的情况。 然后分治处理。 注意在拓一边的时候，如果和当前最小值相等，只能在最小值在左半段或右半段其中一种情况才拓过去。否则比如$1\\space 1$这种区间，会被计算两次。