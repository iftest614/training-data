---
title: " DTOJ2929FarmCraft\t\t"
tags:
  - 树形dp
url: 2075.html
id: 2075
categories:
  - DTOJ
  - Solution
date: 2018-05-25 23:33:06
---

记$f\[i\]$为以$i$为根的子树的电脑全部都装完软件且人回到$i$的最少所需时间，记$size\_i$为以$i$为根的子树大小。 考虑如何求$f\[i\]$。 假如$i$有两个儿子$a$和$b$，是走完$a$的子树还是先走完$b$的子树更优呢？ 如果先走$a$，那么所需的时间是$max\\{f\[a\],2(size\_a-1)+f\[b\]\\}$。 如果先走$b$，那么所需的时间是$max\\{f\[b\],2(size\_b-1)+f\[a\]\\}$。 那么先走$a$更优的条件就是$$max\\{f\[a\],2(size\_a-1)+f\[b\]\\}<max\\{f\[b\],2(size\_b-1)+f\[a\]\\}$$ 其实也就是 $$2(size\_a-1)+f\[b\]<2(size\_b-1)+f\[a\]$$ 即 $$2(size\_a-1)-f\[a\]<2(size\_b-1)-f\[b\]$$ 那么我们对于$i$的所有子树，按$2(size-1)-f$从小到大的顺序走子树最优。 因此dfs一遍就能求出$f\[1\]$了。 注意$f\[1\]$还要和$C\_1+2(n-1)$取个max，因为$1$号点是最后开始装的。