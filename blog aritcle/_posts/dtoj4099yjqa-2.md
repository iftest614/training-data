---
title: " DTOJ4099yjqa\t\t"
tags:
  - dp
  - 线段树
url: 6014.html
id: 6014
categories:
  - Solution
date: 2019-01-13 14:41:56
---

一见到题目“这他妈电梯管理系统？”

后来想到这并不是电梯管理系统...就是一个简单的dp模型。$f\[i\]$为送完前$i$个客人并且回到0层的最小时间。$O(n^2)$的是普及组dp。考虑优化。

显然这个过程是对于一个区间的值加上某段最大值取最小。那么区间的贡献显然是具有单调性的，dp值也是具有单调性的。考虑单调栈处理一维单调性，另外一种情况直接在线段树上查询最小值即可。