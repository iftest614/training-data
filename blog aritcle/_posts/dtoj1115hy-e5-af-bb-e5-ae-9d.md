---
title: " DTOJ1115Hy寻宝\t\t"
tags:
  - 思路
  - 最短路
url: 1076.html
id: 1076
categories:
  - DTOJ
  - Solution
date: 2018-03-18 16:09:06
---

DTOJ1595奶牛选美大赛加强版。 首先有从一个点出发连接四个联通块的方法。 剩下的方法，我们可以先考虑联通三个联通块，再让剩下那个联通块与已联通的最近的一个联通块连接。 那就只用考虑使三个联通块联通。 同样也有从一个点出发连接三个联通块的方法，然后就只有两两联通的方法了。 求出每个点到每块的最短路然后每种方法取个最优解即可。 此题好像还有状压dp的做法。