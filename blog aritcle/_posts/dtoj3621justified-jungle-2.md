---
title: " DTOJ3621Justified Jungle\t\t"
tags:
  - 无标签
url: 2138.html
id: 2138
categories:
  - Solution
date: 2018-05-28 18:32:45
---

求解所有的k，使得这棵树能划分成$k$个大小均为$\\lfloor \\frac{n}{k} \\rfloor$的联通块。 有一个性质，一棵树可以被划分成$k$个大小均为$\\lfloor \\frac{n}{k} \\rfloor$的联通块，当且仅当子树大小为$\\frac{n}{k}$的倍数的点有$k$个。这个性质我们可以考虑其充要的证明: 对于当前树$N$，假设其要能分成$k$个大小为$k$的联通块，那么一定会有$N \\equiv 0 (mod k)$,并且存在一个子树$N'$,$size(N')=k$。那么我们可以继续考虑$N-N'$,划分成$k-1$个大小为$k$的连通块。 那么我们可以知道，大小为$mk$的子树一定可以划分成$m$个联通块。我们已经考虑了树$N$的满足性证明，那么我们需要考虑当不具备上述条件时的结论。这个显然易举出反例，必要性得证。 于是计数一下子树大小...没了