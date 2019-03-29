---
title: " DTOJ1856重建\t\t"
tags:
  - 概率
  - 矩阵树
url: 3608.html
id: 3608
categories:
  - Solution
date: 2018-08-26 15:42:08
---

回顾一下矩阵树定理。

一般的基尔霍夫矩阵是是度数矩阵-邻接矩阵，求出来的东西可以看成是每种生成树上每条边的权值乘起来的和。在一般的生成树计数里，边权可以看作是1。

那么我们推广一下这个矩阵。令边权为通行概率，这个时候，矩阵算出来的是$\\sum \\prod_{(u,v)\\in T}P_{u,v}$

但是我们实际上要求$\\sum \\prod_{(u,v)\\in T}P_{u,v}\\prod_{(u,v)\\not \\in T}(1-P_{u,v})$

那么我们将所有边权手动改为$\\frac{p_{u,v}}{1-p_{u,v}}$,然后最后的答案乘上$\\prod_{(u,v) \\in T} 1-p_{u,v}即可。