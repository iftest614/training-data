---
title: " LOJ569「LibreOJ Round #11」Misaka Network 与测试\t\t"
tags:
  - 二分图
url: 6384.html
id: 6384
categories:
  - Solution
date: 2019-02-08 10:09:24
---

考虑限制，即一块子矩形中1和3的个数相等。 下面证明，所有的2均单独形成一个子矩形。 因为如果在最优方案中存在一个子矩形中包含2，我们可以不选取这个子矩形，而只选取2这个位置，这样得到的方案不会变劣。 而对于任意不包含2的子矩形，其中至少有一对相邻的1和3。我们将所有相邻的1和3选出来作为一个子矩形，这样方案不会变劣。 那么问题就变成了所有相邻的1和3之间的最大匹配。 建出二分图，跑最大匹配，最后加上所有2的个数即是答案。