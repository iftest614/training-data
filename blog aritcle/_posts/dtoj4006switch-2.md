---
title: " DTOJ4006switch\t\t"
tags:
  - 无标签
url: 5272.html
id: 5272
categories:
  - Solution
date: 2018-11-23 12:36:06
---

ex_BFS。 从一个格点走到对角线上的格点有0和1种代价。这个可以很方便的根据图算出来。发现每次横纵坐标分别是同奇偶的，因此一个格子不会经过两次。 求出最短路就可以得到答案。但是求出最短路不需要用spfa。每次对于一条边权为0的就加在队头，否则就加在队尾。那么每次bfs一定是先增广同代价的联通块再增广到下一层的。因此这个可以在每个点访问一次的效率下求出最短路。 效率是$\\Theta(nm)$的。