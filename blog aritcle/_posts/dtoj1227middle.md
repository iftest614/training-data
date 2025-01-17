---
title: " DTOJ1227middle\t\t"
tags:
  - 二分
  - 可持久化线段树
url: 1362.html
id: 1362
categories:
  - DTOJ
  - Solution
date: 2018-04-09 15:01:45
---

对于询问中位数的问题，很容易想到二分答案。 假设二分的答案为$ans$，那我们将$>ans$的数变成$1$，$\\leqslant ans$的数变成$-1$。那么问题就变成了在满足左右端点限制的前提下，是否有区间的和$\\geqslant 0$。 每次询问都二分一次显然不可行。容易想到整体二分，但此题强制在线。 考虑在二分的基础上，如何快速验证答案是否可行。 发现$\[b,c\]$这一段的数是必须要选的，而$\[a,b)$要选出一个左端点，$(c,d\]$要选出一个右端点，那我们可以将区间的和拆成三部分计算。 那么就是要求区间和，最大左子段和，最大右子段和。 联系求最大连续子段和的做法，容易想到用线段树维护。即线段树上维护当前节点代表的区间内的区间和、左/右端点固定另一端点任取的最大区间和。 也就是说要建$n$棵线段树。 注意到如果按数从小到大建树，每次只有log个节点的信息需要更新，那么建一棵可持久化线段树即可。