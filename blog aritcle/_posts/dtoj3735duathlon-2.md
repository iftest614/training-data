---
title: " DTOJ3735Duathlon\t\t"
tags:
  - 圆方树
url: 3843.html
id: 3843
categories:
  - Solution
date: 2018-09-06 19:20:12
---

圆方树上圆方果...

枚举起终点$a$,$b$，答案就是所有$a$到$b$之间简单路径的并的点数。

考虑建立圆方树，将方点的点权标记为点双大小，将圆点点权记为-1。对于两个点$a,b$，方案数就是路径上的点权和。

可以枚举$a,b$计算，效率是$O(n^2)$的。或者我们统计一个点会被计算几次，然后用树形dp计算这个就是线性的了。