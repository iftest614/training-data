---
title: " DTOJ2835Pustynia\t\t"
tags:
  - 线段树
url: 4523.html
id: 4523
categories:
  - DTOJ
  - Solution
date: 2018-10-24 23:25:06
---

md数据范围不在输入里写清楚……没看到构造的数也要在$\[1,10^9\]$，直接从100炸到26。 我们把每个数看成一个点，如果$a$比$b$大，就连一条从$a$向$b$的边。 整张图如果有环的话一定无解。 考虑在图是DAG的情况怎么构造解。 我们可以按照拓扑序依次确定每个点的最大取值，看看和已经确定的点是否有矛盾即可。 现在唯一的问题就是这样直接建图边数是$n^2$的。 我们发现每次都是点向整个区间连边，很容易想到线段树。 而且此图还不需要真正建出图来，只需要维护入度。 那么用线段树维护入度，并且通过维护入度最小值来找到入度为$0$的点即可。