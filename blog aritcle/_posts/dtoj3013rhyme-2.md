---
title: " DTOJ3013Rhyme\t\t"
tags:
  - 奇技淫巧
  - 拓扑序
url: 2301.html
id: 2301
categories:
  - Solution
date: 2018-06-09 20:53:11
---

这题真的很巧妙。 首先串要从一个长度为k的子串开始。每往后接一个字符还要满足后k个字符是一个子串。 那么我们只考虑后k-1个字符。 那么一定满足，后k-1个字符一定是一个子串。可能有许多模板串中有这个k-1个子串。 那么我们可以抽象一下，想那些字符可以接在最后。那么肯定是模板串中该子串的后面某个字符。 那么我们将长度为K-1的子串作为点，每个点有一些出边表示在这个字符串后面加上一个字符可以在保证是子串的条件下让后K-1个字符变成哪个子串。 这就是一张图，所要求的就是图上最长路的长度+k-1。 图上有环的话肯定就inf了。否则拓扑排序就可以找出最长路。 建图的时候可以hash建图。考虑是在模板串内尺取一个长度为K-1的子串，和下一个串连出一条边。用unsigned ll+map来离散。