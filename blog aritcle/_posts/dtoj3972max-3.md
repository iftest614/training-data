---
title: " DTOJ3972max\t\t"
tags:
  - 倍增
  - 分块
  - 线段树
url: 4815.html
id: 4815
categories:
  - Solution
date: 2018-10-30 21:20:02
---

询问区间最大值，$n$很大。可以选用一种你喜欢的数据结构来维护。 常数过大的线段树、不压缩空间的倍增和没有经过处理的树状数组都会被卡。 考虑一种跑的飞快的写法。前面三种写法的渐进时间复杂度均为$\\Theta(N \\log N)$，我们可以把后面那个$\\log$的真数的大小减下去。 对于整个数列，将其分成$\\sqrt{N}$块。对于每块，用线段树维护区间最大值。那么初始建树的效率是$\\Theta(N)$的，空间大小为$2\\Theta(N)$。 考虑查询最大值，就是中间整块的最大值与旁边零散块的最大值的最大值。将线段树维护出来的整块最大值用倍增维护，由于有$\\sqrt{N}$个值，那么预处理的效率是$\\Theta(\\sqrt{N} \\log \\sqrt{N})$。单次查询可以做到$\\Theta(1)$。 然后考虑零散块的答案，我们可以直接在前述的线段树上面查询。这部分的效率是$\\Theta(\\log \\sqrt{n})$。 那么总共的算法效率瓶颈就只有$\\Theta(\\log \\sqrt{n})$的零散块查询了。前面的预处理效率一直都不会超过$\\Theta(N)$，所以常数特别小。 将线段树用zkw实现，常数更小。 注意数据完全随机的性质。我们每次查完整块以后判断一下零散块的总最大值会不会大于刚才中间块的最大值。如果不会那么就不用进线段树查询了。 总时间复杂度$\\Theta(N \\log \\sqrt{N})$，常数特别小。