---
title: " DTOJ3076太空飞船\t\t"
tags:
  - 三分
  - 二分
  - 斜率dp
url: 3620.html
id: 3620
categories:
  - Solution
date: 2018-08-26 17:32:18
---

首先考虑序列上的问题。

先把方差拆开，有：

$$\\begin{aligned}  
ans&=k^2\\sum_{i=1}^{k}(s_i-\\bar{s})^2 \\\  
&=k^2\\sum_{i=1}^{k}s\_i^2+\\bar{s}^2-2s\_i\\bar s\\\  
&=\\sum_{i=1}^{k}s\_i^2k^2+sum^2-2s\_isum k\\\  
&=ksum^2-2ksum^2+k^2\\sum_{i=1}^{k}s_i^2\\\  
&=\\sum_{i=1}^{k}s_i^2-k sum^2  
\\end{aligned}$$

$sum$为$\\sum_{i=1}^{n}L_i$。

然后我们只需要最小化$\\sum_{i=1}^{k}s_i^2$。

那么设$f\[i\]\[j\]$为前$i$个数字，分成$j$段，$\\sum s_i$的最小值。转移很容易写出：

$$f\[i\]\[j\]=\\min_{k \\le j} \\{f\[k\]\[j-1\]+(Suml\_i-Suml\_k)^2\\}$$

时间复杂度￥O(N^2K)￥，恭喜你成功通过了此题。

但是这个东西在环上。所以你还必须枚举环的开头，时间复杂度$O(N^3K)$。

不过这个dp是一个最基本的斜率优化题，斜率优化dp即可做到$O(NK)$，枚举环以后时间复杂度$O(N^2K)$。

但是这个傻逼出题人出了三个画风清奇的1e5数据。给部分分和标算一点关系都没有。

$k=2$，两段和尽量相等最优。就二分枚举开头再二分一个分界点。也可以指针推一下。

$k=3$就枚举一个开头，指针向后推一个分界点，发现代价关于位置是单峰的，再三分出一个分界点。