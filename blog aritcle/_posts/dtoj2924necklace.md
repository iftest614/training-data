---
title: " DTOJ2924necklace\t\t"
tags:
  - 二分图
  - 思路
url: 5611.html
id: 5611
categories:
  - DTOJ
  - Solution
date: 2018-12-17 07:37:28
---

我们发现$N\\leq 9$。 我们考虑搜索出某一种珠子的顺序，比如说阴珠子。 对于一种阴珠子的排列顺序，我们考虑如何往里面插入阳珠子，能使得变暗的珠子最少。 那么问题就变成了，我们现在有$N$个珠子，某些珠子放在某些位置上会变暗，问最少能使得几个珠子变暗。 最小化变暗的珠子，等价于最大化不变暗的珠子。 我们将每个珠子与不会使它变暗的位置连一条边，那么问题就变成了求最大匹配。 用匈牙利算法或者最大流即可。 时间复杂度$\\Theta(8!\\times 最大匹配)$。 $8!$是因为珠子成环，我们实际上可以固定第$1$个阴珠子在最前面。