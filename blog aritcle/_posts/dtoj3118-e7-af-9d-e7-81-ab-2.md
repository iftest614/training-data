---
title: " DTOJ3118篝火\t\t"
tags:
  - 树形dp
url: 2907.html
id: 2907
categories:
  - Solution
date: 2018-07-21 21:19:04
---

这是第一篇用**Typora**与**Mark down extra**编辑的solution。 开始。 看到这题一般会想着搞一搞树形dp...然后看见数据范围就觉得可以$O(n^2)$搞过去...然并卵。 不会写。 记$f\[i\]\[j\]$为以$i$为根的子树全部都被照亮，且第$i$个点是被第$j$个点照亮,所需要的最小代价 。 这样转移一下貌似是过不去的。 于是我们记$g\[i\]$为以$i$为根的子树全被照亮的最小代价。明显的，$g\[i\]=\\min{f\[i\]\[j\]},j \\in \[1,n\]$。 那么有一个转移： $$ f\[i\]\[j\]=\\sum_{son}min(g\[son\],f\[son\]\[j\]-w\_j)+w\_j $$ 结束。