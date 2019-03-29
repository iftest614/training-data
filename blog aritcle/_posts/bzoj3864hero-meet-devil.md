---
title: " BZOJ3864Hero meet devil\t\t"
tags:
  - dp套dp
url: 2454.html
id: 2454
categories:
  - BZOJ
  - Solution
date: 2018-06-15 20:28:37
---

先考虑求LCS的算法。 是一个很傻逼的普及组dp。记$dp\[i\]\[j\]$为$A$串前$i$位和$B$串前$j$位最长公共子序列的长度。 那么有 $$dp\[i\]\[j\]=\\begin{cases} max(dp\[i-1\]\[j\],dp\[i\]\[j-1\]) & A\_i\\neq B\_j \\\ dp\[i-1\]\[j-1\]+1 & A\_i=B\_j \\end{cases}$$ 同时，这个dp是一个在线的算法，我们往后面加字母，也是可以在原来的基础上继续dp的。 假设现在$S$为$A$串，$T$为$B$串。 我们从空串开始，一个一个往末尾加字母作为新的$T$串。 显然我们关心的只是$dp\[i\]\[|T|\]$。（此处及以下的$|T|$均指当前的$T$串长度） 发现$dp\[i\]\[j\]$每次最多只会$+1$。那么我们可以用一个二进制数$S$来表示这个dp数组。 若$S$的第$i$位为$1$，则说明$dp\[i\]\[|T|\]=dp\[i-1\]\[|T|\]+1$，否则$dp\[i\]\[|T|\]=dp\[i-1\]\[|T|\]$。 现在考虑计数。 记$f\[i\]\[S\]$为现在$T$串的长度为$i$，LCS的数组状态为$S$的方案数。 那么我们可以枚举在$T$串末尾加什么字母来转移。 显然对于一个$S$，加某字母转移到的新状态是固定的，和长度无关。 那么我们预处理出每种状态再加一个字母转移到的新状态是什么，就可以直接转移了。这个预处理需要每次把$dp$数组还原出来，求出新的，再压缩成状态。 通过$S$中有几个$1$我们就能知道LCS的长度了。 这就是dp套dp，真神奇。