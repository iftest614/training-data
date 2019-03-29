---
title: " DTOJ3832能力强化\t\t"
tags:
  - dp
  - 奇技淫巧
  - 容斥
  - 期望
  - 概率
url: 2886.html
id: 2886
categories:
  - DTOJ
  - Solution
date: 2018-07-21 12:32:11
---

首先要知道一个东西：[min-max容斥](https://www.cnblogs.com/ljq-despair/p/8678855.html)。 在这题中，我们可以把每种能力看作一种元素，能力等级达到上限就相当于出现了一种元素，我们要求所有元素都出现至少一次的期望步数。 根据min-max容斥，我们有 $$E(max(S))=\\sum_{S'\\subseteq S}E(min(S'))\\times (-1)^{|S'|+1}$$ 那我们就是要求所有的$E(min(S'))$。 在此题中，所有能力是无差别的，因此$E(min(S'))$只和$S'$的大小有关。 所以我们就是要求，一共$i$种能力，其中一个能力达到上限的期望步数。 假设$p\_j$是第$j$次恰好达到上限的概率，那么我们要求的就是$\\sum\_{j=1}^{ik}jp\_j$ 设$p'\_j$是第$j$次还没有达到上限的概率，那么显然有$p'\_j=\\sum\_{s=j+1}^{ik}p\_s$ 那么我们要求的就是 $$\\sum\_{j=1}^{ik}jp\_j=\\sum\_{j=1}^{ik}\\sum_{s=1}^{j}p\_j=\\sum\_{j=1}^{ik}\\sum_{s=j}^{ik}p\_s=\\sum\_{j=0}^{ik-1}p'\_j$$ 现在就是要求所有的$p'\_j$了。 设计一下dp状态，记$f\[i\]\[j\]$为$i$种能力，强化了$j$次，都没有达到上限的方案数。那么显然有$p'\_j=f\[i\]\[j\](\\frac{1}{in})^j$ 为了求出$f\[i\]\[j\]$，我们还得求一个$g\[i\]$，表示一个技能强化$j$次没达到上限的方案数。假如求出了$g$，我们可以枚举新的一种能力强化了几次进行转移，有 $$f\[i\]\[j\]\\times g\[s\]\\times \\binom{j+s}{s}\\Rightarrow f\[i+1\]\[j+s\]$$ 那么现在的问题就是求$g$了。 求$g$我们可以用一个简单的背包dp来解决。记$h\[i\]\[j\]$为强化$i$次，等级为$j$的方案数，$h$很好求，而$g\[i\]=\\sum\_{j=0}^{k-1}f\[i\]\[j\]$。 这样我们就求出了一共$i$种能力，其中一个能力达到上限的期望步数。 但是我们这些推导的过程都是只考虑有$i$种能力，而实际是有$m$种能力，也就是说，会有几次强化作用在剩下$m-i$种能力上。$m$次强化中期望只有$i$次作用在我们这$i$种能力上，因此求出来的期望步数还要乘上$\\frac{m}{i}$。 子集大小为$i$的集合有$\\binom{m}{i}$个，乘上后再代进min-max容斥的式子即可求出答案了。