---
title: " DTOJ2229抢车位\t\t"
tags:
  - dp
url: 5063.html
id: 5063
categories:
  - DTOJ
  - Solution
date: 2018-11-05 23:17:01
---

显然如果存在$j$满足$w\_j\\leq w\_i$且$v\_j\\geq v\_i$，那么第$i$种车肯定是没用的。我们可以把没用的车删掉。 我们可以用当前拥有的车表示当前的状态。具体地，记$f\[i\]\[j\]$表示拥有一辆第$i$种车和一辆第$j$种车的最少时间。 那么答案就是$\\min_{i,j\\in\[1,N\]}\\{f\[i\]\[j\]+\\frac{M-w\_i-w\_j}{v\_i+v\_j}\\}$。 我们每次换车一定是从价值低的换到价值高的，那么我们把所有车按价值从小到大排序。 由于我们已经把没用的车删掉了，因此我们肯定是从第$i$种车换到第$i+1$种最优。并且我们一定是能换的时候就马上换。 那么我们就可以求出$f\[i\]\[j\]$了。 $$f\[i\]\[j\]=\\min(f\[i-1\]\[j\]+\\frac{w\_i-w\_{i-1}}{v_{i-1}+v\_j},f\[i\]\[j-1\]+\\frac{w\_j-w_{j-1}}{v\_i+v\_{j-1}})$$ 时间复杂度$\\Theta(N^2)$。