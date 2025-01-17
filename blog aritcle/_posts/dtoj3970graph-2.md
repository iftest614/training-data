---
title: " DTOJ3970graph\t\t"
tags:
  - 思路
  - 最短路
url: 4785.html
id: 4785
categories:
  - DTOJ
  - Solution
date: 2018-10-29 23:37:25
---

和暴力拍出错然后交上去却AC了，又是一次神奇的经历。 题目要我们给混合图的边定向，使得包含$1$号点的有向环权值和最小。 先考虑暴力。 我们枚举一条与$1$号点相连的边$(1,x)$，然后钦定它的方向是$x\\rightarrow 1$。 然后我们求出$1$到$x$不经过这条边的最短路$dist$，用$dist+v$更新答案。其中$v$是这条边从$x$到$1$的边权。 也就是说，如果包含$1$号点的有向环最后是从$x$到$1$，那么$1$到$x$的最短路就不能经过$1\\rightarrow x$这条边。 换句话说，如果某条最短路是从$1\\rightarrow x$的，那么它最后就不能再从$x\\rightarrow 1$来更新答案。 那么如果我们钦定是从$x$回到$1$，就要找一条从$1$到$x$不走$1\\rightarrow x$的边的最短路来更新答案。 我们维护从$1$出发，到点$i$的最短路$dist1\_i$，以及这条最短路从点$1$出发第一个到达的点$from1\_i$。 同理再维护次短路的$dist2\_i$和$from2\_i$。注意这里的次短路是指从点$1$出发第一个到达的点不同的路径，即保证$from1\_i\\neq from2\_i$的路径中距离最小的一个。 用堆优化的Dijkstra在$\\Theta(n\\log n+m)$内求出即可。 注意更新最短路的时候有一堆细节，要特别注意$from1\_i=0$或$from2\_i=0$的情况。 然后我们枚举一条与$1$相连的边$(1,x)$，如果$1$到$x$的最短路走了$1\\rightarrow x$，就用次短路更新，否则就用最短路更新即可。 Jyc神仙有一种一边正向跑Dijkstra，一边反向跑Dijkstra，然后在任意点汇合的写法，十分神仙。