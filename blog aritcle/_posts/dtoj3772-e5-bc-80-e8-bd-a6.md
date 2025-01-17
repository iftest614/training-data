---
title: " DTOJ3772开车\t\t"
tags:
  - 思路
  - 最小生成树
  - 欧拉回路
url: 2603.html
id: 2603
categories:
  - DTOJ
  - Solution
date: 2018-07-01 14:54:18
---

容易发现题目就是要求一个代价最小的欧拉回路，同时一条边可以经过多次。 由于要经过每条边至少一次，我们可以先考虑每条边都只走一次的情况。 根据欧拉回路的性质，我们可以算出此时每个点的度数，如果都是偶点那么就已经存在欧拉回路了。 否则，与奇点相连的边肯定至少要多走一次。 注意到此题有一个性质：边权是$2^i$。 说明多走一次第$i$条边的代价比多走一次第$1\\sim i-1$条边代价还高。 那么我们肯定是选择一个点能走的边权最小的边走。 容易想到最小生成树，然后在生成树上自底向上判断每个点是否是奇点，如果是奇点就走一次它和父亲之间的边。