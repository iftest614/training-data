---
title: " DTOJ1363楼房重建\t\t"
tags:
  - 线段树
url: 2714.html
id: 2714
categories:
  - Solution
date: 2018-07-06 12:01:20
---

我们注意到，所有能看到的楼房，一定会比之前所有的楼房高。也就是说，它是作为1....i间的最大值存在的。那么我们用线段树维护，对于每个节点我们记录区间最大值，，每个叶节点记录其是否是前区间的最大值。最后v pushup到根时就会是区间内为l...i中最大值的点的个数。