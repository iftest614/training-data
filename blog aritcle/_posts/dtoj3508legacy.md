---
title: " DTOJ3508Legacy\t\t"
tags:
  - 奇技淫巧
  - 线段树
url: 2673.html
id: 2673
categories:
  - DTOJ
  - Solution
date: 2018-07-03 21:40:52
---

线段树优化建图的模板题。大概可以理解成用线段树的节点跑最短路吧，线段树上的每个节点的信息就是这段区间的点的最短路的最小值。 建两个线段树$A,B$。其中，只有叶子节点是对应原图的节点，其它点都是用来优化建图的。 我们先建出用来pushup和pushdown的边：$A$的每个儿子向父亲连边，边权为$0$。$B$的每个非叶结点向儿子连边，边权为$0$。$B$的叶子节点向$A$的叶子节点连边，边权为$0$。 对于$x$到$y$的边，$A$中对应$x$的叶子节点向$B$中对应$x$的叶子节点连边。 对于$x$到$\[l,r\]$的边，$A$中对应$x$的叶子节点向$B$中$\[l,r\]$对应的区间节点连边。 对于$\[l,r\]$到$x$的边，$A$中$\[l,r\]$对应的区间节点向$B$中对应$x$的叶子节点连边。 然后对于两棵线段树上的点跑Dijkstra。 最终$A$（或$B$）中每个叶子节点就是原图对应节点的最短路。