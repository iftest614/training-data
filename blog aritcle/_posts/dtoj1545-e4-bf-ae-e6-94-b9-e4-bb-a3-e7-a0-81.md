---
title: " DTOJ1545修改代码\t\t"
tags:
  - 无标签
url: 4294.html
id: 4294
categories:
  - Solution
date: 2018-10-21 14:05:12
---

对于每个位置，按照其还要修改的空格数$\\Delta_i$贪心考虑。对于一个点其还未修改为$0$，就向后跑全部与他同号的数减去或者加上他们的一个最小值。反复贪心即可。可以证明这是一种最优的方案。