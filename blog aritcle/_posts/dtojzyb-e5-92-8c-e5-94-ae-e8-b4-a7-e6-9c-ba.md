---
title: " DTOJZYB和售货机\t\t"
tags:
  - 思路
  - 环加外向树
url: 5299.html
id: 5299
categories:
  - DTOJ
  - Solution
date: 2018-11-26 18:55:13
---

如果存在$i$，且$C\_i\\geq D\_{fa\_i}$，那么这个开关一定是没有用的，我们可以把这个开关删掉。 对于剩下的开关，我们从$i$向$fa\_i$连一条价值为$C\_i-D\_{fa\_i}$的边。 对于每一个物品，我们一定是从到达它的边中价值最大的来买它。我们定义这样的边为优秀的边。 把所有优秀的边抓出来重新建图，对于每个连通块，一定是一棵树或者基环内向树。 先考虑树的情况。我们根往下依次按每个开关，一定能把所有物品买完。 再考虑有环的情况。我们一定能把所有物品买到只剩一个。对于不在环上的物品，我们也能买完。 对于环上的边，我们考虑断掉一条，那么就变成了一棵树的情况了。 考虑断掉哪条边最优。 假设我们断了$i\\rightarrow fa\_i$的边，那么$fa\_i$可以用其他边来买（不优秀的边），这样一定是选连向$fa\_i$的边中价值次大的边。 那么我们对于环上的所有点，找到连向它的最大值减次大值最小的边，把环上连向这个点的边断掉一定是最优的。 这样就可以计算出最大收益了。 时间复杂度$\\Theta(n)$。