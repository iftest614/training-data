---
title: " DTOJ3575Mathematical Analysis\t\t"
tags:
  - 最小生成树
url: 1153.html
id: 1153
categories:
  - DTOJ
  - Solution
date: 2018-03-21 15:49:24
---

第一次在测试中看出原题很开心。没有调出来，就…更开心了\[微笑\]。 如果求出了最小生成树，那就是倍增求个树上两点路径最大值了。 问题就是求出最小生成树。 暴力建边是$n^2$的，肯定不可取。注意到题目是曼哈顿距离，而曼哈顿距离的最小生成树有很好的性质，就是有用的边数不超过$8n$条，每个点只会向每$45°$中最近的点连一条边，可以证明与其他点连边都不会比这更优。 找最近的点也就是找在那个范围中$x+y$最大的点，这是一个二维偏序的问题，可以用树状数组解决。以$x$排序为第一关键字，$y-x$为第二关键字排序，$y-x$离散后用树状数组维护这一维即可。 注意如果以$x-y$为第二关键字，那么第一关键字是$y$！不然可能会找到不在该范围内的点连边，这就是我测试GG的原因。 由于是无向图，所以其实是向四个部分的点连边。每次作一下相应的坐标变换即可。 举报出题人故意卡int！连距离都要开ll。