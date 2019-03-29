---
title: " DTOJ3561跳马\t\t"
tags:
  - 思路
url: 5263.html
id: 5263
categories:
  - Solution
date: 2018-11-23 09:59:46
---

感觉这题给人一种...式子题的感觉... 首先令$x>y$。当$x \\leq 2y$的时候，我们不能让一边全部走$2$而一边全部走$1$，而这个时候对于$x+y$的均摊方案可以证明是存在唯一解的。因为考虑总共$x+y$个移动，每次可以贡献$3$个移动，然后再判断一下边界条件大概就是最后多出来要返回的部分，那么答案就是$\\frac{x+y}{3}+(x+y) \\mod 3$。 再考虑$x \\ge 2y$的情况。这个时候我们就可以让$x$全部走$2$，$y$全部走1。可以发现这样走是最优的。但是这还有很多情况，譬如说$y$要折返走的情况，这会多出来一部分代价。发现要折返的次数是$(x-2y)\\%4$。那么答案会是$\\frac{x + (x - 2y) \\mod 4}{2}$。 constructive：$x,y \\leq 2$的情况要特判。