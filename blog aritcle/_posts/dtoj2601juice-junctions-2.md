---
title: " DTOJ2601Juice Junctions\t\t"
tags:
  - tarjan
url: 3650.html
id: 3650
categories:
  - Solution
date: 2018-08-27 09:19:50
---

既然每个点最多链接三条管道，那么一个点到另外一个点的流量至多为3。

考虑当满足什么条件的时候，两点之间的流量为0/1/2/3。

*   当两个点不连通时，流量为0.
*   当两个点联通时，流量至少为1.
*   当两个点在同一个点双内时，流量至少为2
*   当两个点在同一个点双内，并且任意删掉一条边还在同一个点双内时，流量为3.

依照上面分类讨论，求出点双后，每次删掉一条边后再求一次点双，然后把每次属于哪个点双hash起来，最后暴力判断是否合法。