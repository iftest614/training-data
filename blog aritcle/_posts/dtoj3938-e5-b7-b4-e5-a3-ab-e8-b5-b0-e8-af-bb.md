---
title: " DTOJ3938巴士走读\t\t"
tags:
  - 最短路
url: 4040.html
id: 4040
categories:
  - Solution
date: 2018-09-23 15:56:09
---

我的写法是真的臭 常数直接大了三倍...

就是我们可以处理出经过起点的每条出边到终点的最短路长度，然后就可以知道在最晚的时候什么时候走比较优了。

然而这个怎么求呢。我们继续dfs。

对于到达某点的时刻$t$，显然时刻$< t$的出边都不能走了。然后我们依次枚举每条边并走到下一个点，同时记录当前的时刻。就可以求得某个点到n的最小花费了。

然而这样会有及其大量的无用状态。考虑到当我们到达每个点的时候，时刻总是只有几个，等于其所有入边的到达时刻。于是我们每次顺便保存一下这个点在时刻t到达时的最小答案，那么所有点至多会被访问$m$次了。算上每次开头那个二分，效率是$O(m log m+Q log n)$