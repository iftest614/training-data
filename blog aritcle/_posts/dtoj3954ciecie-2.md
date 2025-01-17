---
title: " DTOJ3954Cięcie\t\t"
tags:
  - 数学
url: 4487.html
id: 4487
categories:
  - DTOJ
  - Solution
date: 2018-10-24 15:29:29
---

我们维护每个前缀$\\%p$的值和每个后缀$\\%r$的值，那么前缀$\\%p=o$的位置就是可以作为第一段结尾的位置，后缀$\\%r=0$的位置就是可以作为第三段开头的位置。 而知道第一段结尾和第三段开头就相当于知道了第二段的开头和结尾。 那么问题就变成了如何统计合法的第二段的数量。 记$Sum\_i=(\\sum\_{j=i}^{k}a\_j\\times 10^{k-j})\\%q$。即从$i$开始的后缀$\\%q$的值。 区间$\[l,r\]$可以作为第二段，当前仅当$Sum\_{l}-Sum_{r+1}=0$，即$Sum_{l}=Sum_{r+1}$，因为题目保证了$q$是质数且$\\geq 2015$。 那么我们将合法的开头和合法的结尾都从小到大排序，然后枚举结尾，维护当前合法开头每种$Sum$值的个数即可计算合法的第二段数量。 要注意区分前导$0$和单独的$0$的区别。