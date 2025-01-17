---
title: " DTOJ3636IIIDX\t\t"
tags:
  - 线段树
  - 贪心
url: 3555.html
id: 3555
categories:
  - Solution
date: 2018-08-24 21:06:45
---

我们发现那个奇怪的东西...这不就相当于一个$k$叉树嘛！

第$i$个点的父亲是$\\lfloor \\frac{i}{k} \\rfloor$。出现森林的话就新建0节点，权值设为无穷小。然后我们按照后序遍历贪心放数字就可以得到最优解。

貌似这应该比T1简单地样子。

但是。数字并不保证两两不同。

所以上面那个 看起来很显然 的贪心就错了。

依次贪心。我们要先让第一个点的值尽可能的大，确定完第一个点以后再让第二个点的值尽可能的大，以此类推...

我们先将所有数从从大到小排序。然后，我们设 $F\_i$ 表示第 $i$ 个结点左边已被预定的数的数量（初始为 0）, 那么 $i-F\_i$ 即为第$ i $个结点左边可用数的数量。

我们依次考虑每个结点$x$，设结点$x$的子树大小为$size$。

那么我们要找到一个最小的位置$p$，使得$\\forall i\\in\[p,n\], \  i-F\_i \\geq size$。那么结点$x$的值就是$A\_p$。接着我们要在$A\_1 - A\_p$中选$size-1$个给结点$x$的儿子，即要为儿子预定一些位置，那么我们给$<A\_p$的位置$i$的$F\_i$减去$size$，同时最右边的$A_p$的位置也要减去$size$。

也可以这么理解：每次选一个数给某个结点都需要提前预定一些数等后面放在子树内。 那么我们要做的就是判断某次选择后，前面结点的预定能否被满足， 然后在此基础上让解最大。

以上操作皆可用线段树实现。 复杂度 O(nlogn)