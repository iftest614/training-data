---
title: " DTOJ1586BLO\t\t"
tags:
  - tarjan
url: 1984.html
id: 1984
categories:
  - DTOJ
  - Solution
date: 2018-05-15 13:32:29
---

发现对于一个不是割点的点，删掉它只会使得以它为起点/终点的点对不能连通。 否则，如果是割点，删掉它会剩下很多个互相不连通的连通块，在两个不同的连通块中分别取一个点，在删掉当前点之后都无法连通。 计算每个连通块的大小只要在求割点的过程中，即tarjan过程中，维护dfs树的子树大小。