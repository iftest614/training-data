---
title: " DTOJ2162magic\t\t"
tags:
  - 最小割
url: 761.html
id: 761
categories:
  - DTOJ
  - Solution
date: 2018-02-25 20:43:41
---

对于图中的一个点$i$，把$i$连出去的点$j$按照$a\[j\]$从大到小排序，记排序完后为$x\_1,x\_2,…,x\_m$。 如果$w\_i=a\[x\_k\]$，则说明我们需要使所有的$a\[x\_t\]=0(t<k)$。 感觉和闭合子图的定义有点像，由于题目求的是最小代价，考虑最小割的建图。 $S$向$x\_1$连容量为$a\[x\_1\]$的边，$x_{i-1}$向$x\_i$连容量为$a\[x\_i\]$的边。 割掉某条边的意义就是$w\_i$等于这条边的容量。 由于要使所有的$a\[x\_t\]=0(t<k)$，我们得花费$\\sum_{u=1}^{k-1}b\[x\_u\]$的代价。对于每个点，往$T$连容量为$b$的边。这样割掉代表$w\_i$的边时，也要把$x_t(t<k)$连向$T$的边一起割掉。 用最大流跑出最小割即为答案。 值得注意的是，对于图中不同的点$i$，它们连出去的点$j$可能有重复，这样直接建边的话因为残余网络的反向边会导致一些多余的费用。因此我们需要将一个点拆成多个点，对于每个$j$都新建一个虚拟点连边，虚拟点再向$j$连容量为$inf$的边，$j$向$T$连容量为$b\[j\]$的边即可。