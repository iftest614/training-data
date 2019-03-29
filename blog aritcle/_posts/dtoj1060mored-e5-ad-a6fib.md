---
title: " DTOJ1060moreD学FIB\t\t"
tags:
  - dp
url: 2261.html
id: 2261
categories:
  - DTOJ
  - Solution
date: 2018-06-08 15:07:46
---

发现fib数列增长速度很快，差不多到第$90$项左右就$>10^{18}$了。因此所有方案里会用到的数最多只有$90$种。 首先我们找出用的数的个数最少的拆分，显然这个拆分是唯一的。记拆成了$m$个数，从小到大第$i$个数为fib的第$a\_i$项。 然后剩下的方案一定是把这种方案里的某些数换成了另外一些数。由于fib数列优秀的性质：每项等于前两项之和。那么替换的方案一定是把第$a\_i$项换成第$a\_i$项之前的数之和。 记$f\[i\]$表示只替换前$a\_i$项中的某些数的方案数。 那么有 $$f\[i\]=f\[i-1\]\\times\\lceil \\frac{a\_i-a\_{i-1}}{2}\\rceil$$ 即考虑有多少种用$a_{i-1}$项后的数替换掉第$a\_i$项的方法。 特殊地，如果$(a\_i-a_{i-1})\\%2=0$，那么有$f\[i\]+=f\[i-1\]-f\[i-2\]$。即再凑出一个第$a_{i-1}$项的方案数。 答案即为$f\[m\]$。