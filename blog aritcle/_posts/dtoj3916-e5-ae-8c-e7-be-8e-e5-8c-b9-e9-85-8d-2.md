---
title: " DTOJ3916完美匹配\t\t"
tags:
  - 状压dp
url: 3966.html
id: 3966
categories:
  - Solution
date: 2018-09-16 20:27:17
---

我们可以想到状压一个状态：S为已用过点的数量。然后我们每次枚举一条出边转移。看起来效率是$O(n2^n)$的。但是其实我们会舍弃掉大量的无用状态。所以我们记忆化搜索来做dp，总共有用的状态数大概就是1e6的级别的。