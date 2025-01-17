---
title: " DTOJ2754Count\t\t"
tags:
  - dp
url: 415.html
id: 415
categories:
  - DTOJ
  - Solution
date: 2018-01-25 20:50:54
---

考虑从低到高往桌上放书。那么我们可以考虑把绝对值拆开算，每个绝对值对答案的贡献拆成多个相邻的高度差。这样按高度从低到高排序后，放入第$i$个数对答案影响就是$h\[i\]-h\[i-1\]$的倍数。 具体的，令$f\[i\]\[j\]\[k\]\[0/1\]\[0/1\]$为放了前$i$个数，$i$个数中间有$j+1$个数没有相邻（也就是中间有$j$个空位），混乱程度为$k$，有/无确定的开头/结尾。有了开头就不能往最前面放数，结尾同理。 于是我们可以通过空位数和有无开头/结尾知道最多有几个可以放数的位置，记为$cnt$。则$cnt=j\*2+\[无开头\]+\[无结尾\]$，因此代价为$cnt\*(h\[i\]-h\[i-1\])$，可以进行转移。新放一个数可以放在已有一个数的旁边，这样空位数不变；也可以放在某个空位中间，使空位数$+1$；还可以把某个空位占掉，使空位数$-1$。同时还能使这个数成为开头/结尾。 初始有$f\[1\]\[0\]\[0\]\[0/1\]\[0/1\]=1$。答案为$\\sum_{i=0}^{i\\leqslant L}f\[n\]\[0\]\[i\]\[1\]\[1\]$。 用$0/1$压掉第一维即可以满足空间限制。