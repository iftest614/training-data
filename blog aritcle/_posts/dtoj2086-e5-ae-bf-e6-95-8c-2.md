---
title: " DTOJ2086宿敌\t\t"
tags:
  - dp
url: 2544.html
id: 2544
categories:
  - Solution
date: 2018-06-17 15:02:37
---

注意到

> **不同的实力值不会超过****1,000****个。**

我们分开计算形成单调递增和形成单调递减序列的代价。 首先将实力值离散化，设$f\[i\]\[j\]$为前i个人单调不增（不减同理），第i个人的实力（离散后）大于等于j的代价。 则有转移$$f\[i\]\[j\]=min\\{f\[i\]\[j-1\],f\[i-1\]\[j\]+cost(p\_i,j)\\}$$ 其中$cost(a,b)$为将$a$改成$b$的代价。 然后滚动数组滚掉一维，就可以计算答案了。时间复杂度$O(n tot\_{p_i})$