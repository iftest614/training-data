---
title: " DTOJ3942CYC的帝国\t\t"
tags:
  - 并查集
  - 最小生成树
url: 4275.html
id: 4275
categories:
  - DTOJ
  - Solution
date: 2018-10-21 12:17:29
---

有一点针对数据结构写傻选手233 先求出mst，对于不在mst上的边，答案肯定是inf。 对于在mst上的边，我们要计算它边权增加多少会被一条非CYC的边替代，即可能替代它的边的边权最小值减去它的边权。 一条不在mst中的边$(u,v,w)$，替代的边就是mst上从$u$到$v$中边权最大的边。即要求$u$到$v$经过的每条CYC的边的边权都要$\\leq w$。 拿不在mst中且非CYC的边去更新CYC边的答案即可。 然后数据结构写傻选手就会去乖乖码树剖+线段树。 但实际上，由于我们是用边权去更新答案，如果边权按从小到大去更新的话，每条边的答案就只会被更新一次，即第一个能替代它的边的边权。 那么对于一条不在mst中的边$(u,v)$，我们可以暴力地在mst从$u$走到$v$，把经过的CYC的边的答案更新了。然后用并查集压掉已经更新过的路径。 时间复杂度$\\Theta(n\\log \\alpha + m\\log m)$。