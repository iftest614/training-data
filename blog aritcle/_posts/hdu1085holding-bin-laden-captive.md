---
title: " HDU1085Holding Bin-Laden Captive!\t\t"
tags:
  - 生成函数
url: 253.html
id: 253
categories:
  - Solution
  - 其他OJ
date: 2018-01-17 15:17:00
---

记价值为$1$的硬币有$n$个，$2$的有$m$个，$5$的有$k$个。 用价值有$1$的硬币能组成的价值的多项式为$（1+x^1+x^2+x^3+…x^n）$。 用价值有$2$的硬币能组成的价值的多项式为$（1+x^2+x^4+x^6+…x^{2m}）$。 用价值有$5$的硬币能组成的价值的多项式为$（1+x^5+x^{10}+x^{15}+…x^{5k}）$。 三个多项式相乘，按$x$的升幂排序，第一个系数为$0$的项就是最小的不能组成的价值。 如果没有则为$n+m\\times 2+k\\times 5$。 类似的题有HDU1171Big Event in HDU和HDU2152Fruit。