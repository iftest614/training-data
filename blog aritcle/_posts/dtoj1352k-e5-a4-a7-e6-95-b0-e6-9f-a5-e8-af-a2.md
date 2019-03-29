---
title: " DTOJ1352K大数查询\t\t"
tags:
  - 树套树
url: 2652.html
id: 2652
categories:
  - Solution
date: 2018-07-02 21:16:47
---

（线段）树套（线段） 树好题。 先将数据离散化。假设仅有单点修改，我们可以利用一层权值线段树来维护区间第k小。然后在树状数组套主席树即可解决。 那么我们考虑怎么处理多个数的情况。 我们对于第一层的权值线段树，每个节点开一棵区间线段树。对于每个区间修改操作，我们在内层的区间线段树上区间修改，而后对于每个节点，可以知道（离散化后）值域在\[l1,r1\]间，在区间\[l,r\]中的数字个数。同样地线段树上二分即可解决。