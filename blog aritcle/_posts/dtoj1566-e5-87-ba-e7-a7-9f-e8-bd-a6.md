---
title: " DTOJ1566出租车\t\t"
tags:
  - 贪心
url: 4427.html
id: 4427
categories:
  - DTOJ
  - Solution
  - 不会证
date: 2018-10-23 19:31:19
---

对于每头奶牛，一定要将它从$s\_i$送到$t\_i$，代价为$|s\_i-t\_i|$，这部分对答案的贡献是固定的。 然后每次送完一头奶牛后，都要去另一头奶牛的起点，即从一个$t\_i$到一个$s\_i$。 由于从$0$出发，到$M$结束，所以我们把$0$当作一个$t$，$M$当作一个$s$。 考虑怎么样能让多余的行程最短。 贪心考虑，将所有的$s\_i$和$t\_i$从小到大排序，每次都从$t\_i$到$s\_i$一定最优。 好像可以用反证法证明交换$s$或$t$中任意两个数不会使答案更小。具体没证过。