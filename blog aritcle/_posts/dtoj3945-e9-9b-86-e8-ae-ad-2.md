---
title: " DTOJ3945集训\t\t"
tags:
  - dp
  - 思路
url: 4315.html
id: 4315
categories:
  - DTOJ
  - Solution
date: 2018-10-21 22:36:20
---

虽然维数很大，但走的步数很少，因此只有一些维上不是$1$。 显然每维之间是独立的，我们可以对于每维分开考虑。 记$f\[i\]\[j\]$为某一维用$i$步走到$j$的方案数，这个可以随便dp出来。 然后我们发现坐标范围很小，说明有很多$c\_i$是相同的，我们把$c\_i$相同的合在一起考虑。 假设我们当前考虑的$c\_i=x$，且$c\_i=x$的$i$共有$tot$个。 记$g\[i\]\[j\]$为使$i$个坐标走到$x$或者$1$（其他坐标不动），共用了$j$步的方案数。 那么有 $$g\[i\]\[j\]\\times (f\[k\]\[x\]+f\[k\]\[1\])\\times \\binom{j+k}{k}\\Rightarrow g\[i+1\]\[j+k\]$$ 再记$h\[i\]$为移动$i$次的答案。 那么有 $$h\[i\]\\times g\[j\]\[k\]\\times \\binom{i+k}{k}\\binom{tot}{j}\\Rightarrow h\[i+j\]$$ 最后$h\[q\]$就是答案。 听说好像还可以把暴力dp的式子看成多项式然后$c_i$相同的就可以多项式快速幂搞。