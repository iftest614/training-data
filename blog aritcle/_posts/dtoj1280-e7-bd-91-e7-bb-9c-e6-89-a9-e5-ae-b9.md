---
title: " DTOJ1280网络扩容\t\t"
tags:
  - 最大流
  - 费用流
url: 1243.html
id: 1243
categories:
  - DTOJ
  - Solution
date: 2018-03-26 22:30:12
---

问题$1$简直就是戏耍智商，直接跑最大流。 问题$2$也很简单，在残余网络的基础上给原图每条边都再加一条容量为$K$，费用为$1$的边。 然后控制$S$到$T$的最大流为$K$。 跑一边最小费用最大流即可。