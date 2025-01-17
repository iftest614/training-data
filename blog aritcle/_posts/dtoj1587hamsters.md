---
title: " DTOJ1587Hamsters\t\t"
tags:
  - dp
  - 矩阵
url: 2806.html
id: 2806
categories:
  - DTOJ
  - Solution
date: 2018-07-18 18:28:38
---

显然要求的字母序列一定以某个名字结尾最优。 那么我们可以设计出一个dp：记$f\[i\]\[j\]$为一共出现了$i$个名字，以第$j$个名字结尾的最短长度。答案即为$min_{i=1}^{n}\\{f\[m\]\[i\]\\}$。 我们可以枚举新的字母序列是以哪个名字结尾，那么有 $$f\[i\]\[j\]+len\_k-LCP(j,k)\\Rightarrow f\[i+1\]\[k\]$$ 其中，$len\_i$是第$i$个串的长度，$LCP(i,j)$是第$i$个串和第$j$个串的最长公共前缀的长度。 容易发现，这个转移可以写成一个矩阵的形式，第$i$行第$j$列的值就是$len_j-LCP(i,j)$，每次转移就是把矩阵乘的对应位置乘积和改成对应位置相加然后取min。 那么用矩阵快速幂优化一下即可。 （听说这个叫倍增floyd啊…