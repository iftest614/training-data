---
title: " DTOJ2978Lucky\t\t"
tags:
  - 容斥
  - 数论
url: 5014.html
id: 5014
categories:
  - Solution
date: 2018-11-02 16:24:38
---

题目给出了一系列$x \\not \\equiv b\[i\] \\mod a\[i\]$的限制，还有一个$x \\equiv 0 \\mod 7$。

那么这个东西可以应用容斥原理来解决：答案等于满足$x \\equiv 0 \\mod 7$的所有方程中，总的数量减去一个不符合的数量加上两个不符合的数量减去三个不符合的数量...简单来说就是一个$-1$的容斥系数。

那么我们枚举二进制状态表示一个方程选或不选。然后由于全部的$a$都是质数，并且$\\prod \\leq 10^{18}$，那么我们可以应用中国剩余定理求出合并后的同余方程，那么就可以算出区间内相应不符合的数量了。

边界条件需要特别注意，然后可能需要用到慢速乘。反正我没用。