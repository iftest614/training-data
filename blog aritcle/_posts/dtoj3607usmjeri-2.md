---
title: " DTOJ3607usmjeri\t\t"
tags:
  - 无标签
url: 1944.html
id: 1944
categories:
  - Solution
date: 2018-05-11 16:54:41
---

我们考虑原题要求的性质。将边相对于根的方向转化为颜色，那么点对$(a,b)$的要求满足以下条件： 我们记$c=lca(a,b)$,那么有：

*   a-c的路径上的边颜色相同
*   b-c的路径上的边颜色相同
*   a-c的路径上的边的方向与b-c的路径上的颜色不同，即a-fa\[a\]和b-fa\[b\]的颜色不同

我们可以按照以上的限制连出边，如果有一个联通分量不能满足则答案为0，否则答案将会是2^联通块数目。 但是我们考虑，对于每个限制暴力连限制边的效率是很烂的，我们要考虑如何连边。 我们记一个数组high\[i\]为点i及其子树中的点的询问的lca的深度的最小值（最高的lca）。考虑u与子节点v连有一条限制边的唯一条件，当且仅当high\[u\]>deep\[u\]。否则这条边就不会被连。 那么这样连边的复杂度是O(n)的，总共最多连出$n+m$条边。 接下来对于这张限制的图，用染色法判断不合法以及联通块个数即可。