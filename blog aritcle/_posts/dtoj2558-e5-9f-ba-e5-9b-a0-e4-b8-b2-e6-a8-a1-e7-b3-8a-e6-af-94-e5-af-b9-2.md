---
title: " DTOJ2558基因串模糊比对\t\t"
tags:
  - FFT
url: 2675.html
id: 2675
categories:
  - Solution
date: 2018-07-04 07:36:03
---

首先不考虑模糊匹配的情况，考虑普通的字符串匹配。 假设$S$为模式串，$T$为匹配串。对于模式串关于匹配串从i点开始匹配，匹配个数为$\\sum_{j=1}^{m}\[S_{i+j-1} = T\_j\]$。当等于m时则匹配成功。 考虑将T串翻转，那么每个位置上的匹配个数就变成了$\\sum\_{j=1}^{m}\[S_{i+j-1} = T_{m-j+1}\]$。 这是一个卷积的形式，可以考虑FFT优化解决。 枚举字符集中的一个字符，将所有出现的位置的多项式系数赋为1.做一次FFT即可得到当前位置开始，两串关于这个字符的匹配次数。对于所有字符都做一遍即可知道两串是否匹配。 那么对于本题的模糊匹配，由于每个字符出现的位置，对相邻k位都能产生贡献。于是对于S串中一个字符，将左右k个位置全部赋为1.再做FFT即可得到该字符的模糊匹配次数。