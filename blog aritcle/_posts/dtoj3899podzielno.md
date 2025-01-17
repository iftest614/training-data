---
title: " DTOJ3899Podzielno\t\t"
tags:
  - 二分
url: 4012.html
id: 4012
categories:
  - DTOJ
  - Solution
date: 2018-09-22 15:06:42
---

我们可以通过10进制来思考这题。 根据常识可以知道，一个数每位之和如果是$9$的倍数，那么这个数就是$9$的倍数。 推广一下，一个$B$进制数每位之和如果是$B-1$的倍数，那么这个数就是$B-1$的倍数。 这是很显然的，我们随意证明一下。 设这个$B$进制数从低到高每位分别为$B\_0,B\_1,B\_2,…,B\_n$，那么这个数就是$\\sum_{i=0}^{n}B\_i\\times B^i$。 而$B^i\\equiv 1(mod\\space B-1)$，所以$\\sum\_{i=0}^{n}B\_i\\times B^i\\equiv \\sum\_{i=0}^{n}B\_i\\equiv 0(mod\\space B-1)$。 证毕。 记$Sum=\\sum\_{i=0}^{B-1}ia\_i,len=\\sum\_{i=0}^{B-1}a_i$。

*   如果$Sum\\%(B-1)=0$，那么最大的合法的数一定是$len$位。
*   如果$Sum\\%(B-1)>0$，那么最大的合法的数一定是$len-1$位，且就是能组成最大的数去掉一位$Sum\\%(B-1)$。

那么我们就知道每个数字在最大合法的数中一共有几个，且肯定是大的数字排在前面。 那么询问的时候随便二分一下即可。