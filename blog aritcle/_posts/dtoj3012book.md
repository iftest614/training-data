---
title: " DTOJ3012Book\t\t"
tags:
  - 二分图
url: 3137.html
id: 3137
categories:
  - DTOJ
  - Solution
date: 2018-07-28 14:46:03
---

题目给出的交换规则，其实就是随便换。 也就是说对于任意一个长度为$n$排列$P$，第$i$个人拿到第$p_i$个人带来的邮票都是可行的。 感性理解一下这就是一个二分图匹配。 人和邮票各建一排点，人和喜欢的邮票之间连一条边。 如果最大匹配是$n$答案就是YES，否则就是NO。 吐槽一下数据，第一次见到匈牙利跑的比网络流慢。