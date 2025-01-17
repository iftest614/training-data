---
title: " DTOJ4057字符串\t\t"
tags:
  - 思路
  - 莫队
url: 5540.html
id: 5540
categories:
  - Solution
date: 2018-12-16 11:32:51
---

首先考虑一个傻逼莫队。 建出可持久化Trie。每次莫队移动区间相当于增删一个字符串。我们沿着Trie树跑一下字符串所在的链，然后用set维护一下上一个$len$出现的位置就可以维护答案了。 对于莫队，需要按照字符串长分块，使得每块串长均衡。 这样做的效率是$O(S\\sqrt{S}\\log n)$的。包被卡。 前面那个貌似无从下手了。我们考虑优化那个log。 丢掉没什么卵用的可持久化Trie。依然用前面的维护方法跑链。区别在于每次在链上我们不用set（或者其他带log的数据结构）维护，转而使用链表。 链表的特殊性在于，其删除与查找前驱后继都是$O(1)$的，但是插入需要花费大量时间。我们将莫队对于这个特性做修改。 每次对于每块，按照右端点倒序排序，左端点按块排序。那么每次处理，右端点都是逐渐缩小的。 那么我们每次在处理这块之前先将所有元素加入链表。那么接下来右端点左移，我们只需要做删除操作就好了。 但是左端点也会移动。左端点移动范围在$\\sqrt{n}$中，于是我们可以一开始将左端点放在最左侧，每次对于一个新区间，移动左端点，并且将删去的元素记下。做完当前区间以后推栈再还原就好了。 于是就去log换常数了。