---
title: " DTOJ3557共享单车\t\t"
tags:
  - dp
  - 决策单调性
  - 分治
url: 1082.html
id: 1082
categories:
  - DTOJ
  - Solution
date: 2018-03-18 22:09:57
---

公路会被$k$个存车点划分成$k$段区间，第$i$段区间的居民离第$i$个存车点最近。显然对于区间$\[i,j\]$，我们可以通过二分在$log$的时间内求出$\[i,j\]$中的居民到$\[i,j\]$内最近的存车点的代价，记为$cost(i,j)$。那么问题就变成了最优的区间划分问题。 记$f\[i\]\[j\]$为第$j$段区间右端点为$i$的最小代价。显然可以先枚举$j$然后压掉这一维，那么就剩$f\[i\]$了。考虑上一段区间的右端点为$k$，那么$f\[i\]=min(f\[k\]+cost(k+1,i))$。假设$f\[i\]$的最优决策点是$k1$，$f\[i+1\]$的最优决策点是$k2$，那么一定有$k1\\leqslant k2$。 假设$k1>k2$，那么从$f\[i\]$的转移得知$\[k2,k1\]$的居民走到前面区间内更优，从$f\[i+1\]$的转移得知$\[k2,k1\]$的居民得知走到$i+1$更优，而走到$i+1$又比走到$i$劣，矛盾。 考虑用分治求出$f$。记$Solve(l,r,x,y)$为已知最优决策点在$\[x,y\]$中，求出$f\[l\]\\sim f\[r\]$的最优解过程。那么每次我们找到$\[l,r\]$中的$mid$，求出$f\[mid\]$的最优决策点$pos$，那么$\[l,mid-1\]$的最优决策点一定在$\[x,pos\]$中，$\[mid+1,r\]$的最优决策点一定在$\[pos,y\]$中。划分成子问题用$Solve(l,mid-1,x,pos)$和$Solve(mid+1,r,pos,y)$递归求解即可。