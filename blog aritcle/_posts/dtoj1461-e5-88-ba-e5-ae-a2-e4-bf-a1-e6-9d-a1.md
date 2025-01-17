---
title: " DTOJ1461刺客信条\t\t"
tags:
  - 二分图
  - 树形dp
url: 3433.html
id: 3433
categories:
  - DTOJ
  - Solution
date: 2018-08-12 21:45:16
---

题意是改变点的状态使得两棵树同构且对应点状态要相同。 先了解一下树同构。 有根树同构可以用树hash，把树的各种信息hash起来。据说特别容易碰撞，但这题单hash就过了。 无根树同构我们就抓重心起来当根，如果有两个重心就新建一个点向两个重心连边，然后把新建的点当根，然后就和有根树同构一样了。 这题的话，我们记$f\[i\]\[j\]$表示第一棵树（初始状态）以$i$为根的子树和第二棵树（最终状态）以$j$为根的子树同构且对应点状态相同的最小代价。 那么$i$的每个子树和$j$的每个子树的状态要一一对应，那么这就是一个二分图带权匹配的问题。 如果$i$的子树$x$和$j$的子树$y$同构，那么在左边的第$x$个点和右边的第$y$个点之间连一条代价为$f\[x\]\[y\]$的边。 那么最小权匹配就是$f\[i\]\[j\]$了，如果$i$和$j$状态不同的话还要$+1$。 求最小权匹配可以跑最小费用最大流，也可以用KM算法。 最后答案就是$f\[root\]\[root\]$。