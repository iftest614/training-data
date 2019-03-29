---
title: " DTOJ3561跳马\t\t"
tags:
  - 奇技淫巧
url: 1110.html
id: 1110
categories:
  - DTOJ
  - Solution
date: 2018-03-19 21:10:07
---

从$(0,0)$可以跳到任意一个位置，因此不会有无解的情况。$(0,0)\\rightarrow (2,1)\\rightarrow (0,3)\\rightarrow (1,0)$，因此$(0,0)$能跳到任何一个地方。 显然$x,y$的正负是不影响答案的，不妨设$x\\geqslant y\\geqslant 0$。发现当$x,y$大的时候，肯定有一种最优的方案是在起点跳到某个特定的位置（大约在$8\\times 8$的区域内），然后大量的$(+1,\\pm 2)(+2,\\pm 1)$跳到$(x,y)$。 分两种情况讨论。

1.  $x<2y$。根据$(x+y)\\%3$略有不同：若$(x+y)\\%3=0$，答案是$\\frac{x+y}{3}$，即控制$(+1,+2)(+2,+1)$的数量；若$(x+y)\\%3=1$，答案是$\\lfloor \\frac{x+y}{3}\\rfloor +1$，即先跳两步到$(4,0)$，再跳到$(x,y)$；若$(x+y)\\%3=2$，答案是$\\lfloor \\frac{x+y}{3}\\rfloor +2$，即先跳两步到$(2,0)$，再跳到$(x,y)$。
2.  $x\\geqslant 2y$。那么先跳到$(2y,y)$附近，然后$(+2,-1)(+2,+1)$跳到$(x,y)$。根据$(x-2y)\\%4$略有不同，同上分类讨论一下。如果觉得分类讨论麻烦的话可以先打一个小表，然后先到周围一圈的位置，再乱跳跳到$(x,y)$。乱跳就是先$(+2,-1)(+2,+1)$跳到$(x,y)$附近一圈，然后用打出来的表直接计算到$(x,y)$的步数。

若$x,y$都挺小还需要特判，嫌麻烦同样可以打一个小表。