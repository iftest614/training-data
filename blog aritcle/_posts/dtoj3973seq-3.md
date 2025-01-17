---
title: " DTOJ3973seq\t\t"
tags:
  - 线段树
url: 4808.html
id: 4808
categories:
  - DTOJ
  - Solution
date: 2018-10-30 21:14:50
---

这题是经典问题[DTOJ1363楼房重建](http://www.dtenomde.com/author=jiangyutong/article=2163/)的变形。 显然$p\_i$是单调不降的。 我们考虑用线段树维护$p\_i$。 对于线段树上对应区间为$\[l,r\]$的点，我们维护在只考虑$\[l,r\]$中的$a\_i$情况下，$\\sum\_{i=l}^{r}p\_i$的值和$a\_i$的最大值。 那么询问就是根节点的信息。 现在考虑修改，考虑从左右儿子合并出当前点的信息。 最大值很好维护，问题就是怎么维护$p\_i$的和。 显然左半边的和就是左儿子的$p\_i$的和，但是左儿子的$p\_i$可能会影响到右儿子的$p\_i$，因此我们求出拿左儿子的$a\_i$最大值更新右儿子后，右儿子$p\_i$的和。 假设我们现在要拿$v$取更新$\[l,r\]$的$p_i$。我们分类讨论一下。

*   如果$\[l,r\]$中最大的$a\_i$都$\\leq v$，那么$\[l,r\]$中所有的$p\_i$都会被修改成$v$，直接求和即可。
*   记$\[l,mid\]$为$\[l,r\]$节点的左儿子。
    *   如果$\[l,mid\]$中最大的$a\_i$都$\\leq v$，那么$\[l,mid\]$的所有$p\_i$都会被修改成$v$，然后我们递归去求拿$v$更新$\[mid+1,r\]$的结果皆可。
    *   如果$\[l,mid\]$中最大的$a\_i>v$，那么说明$v$不会影响到$\[mid+1,r\]$。我们递归去求拿$v$更新$\[l,mid\]$的结果，再加上$\[mid+1,r\]$中$p\_i$的和即可，注意这里$\[mid+1,r\]$的和要拿未更新时$\[l,r\]$的和减去未更新时$\[l,mid\]$的和。

由于每次更新只有一条路径往下走，因此每次更新是$\\Theta(\\log n)$的。 每次修改要更新一条链上的节点，共有$\\log n$个。 因此总时间复杂度是$\\Theta(n\\log ^2 n)$的。