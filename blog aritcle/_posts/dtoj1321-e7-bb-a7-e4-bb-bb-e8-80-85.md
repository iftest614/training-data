---
title: " DTOJ1321继任者\t\t"
tags:
  - 线段树
url: 679.html
id: 679
categories:
  - Solution
date: 2018-02-19 17:31:14
---

这题连树剖都不用。 一个点的子树在dfs序上一定是连续的。 那么我们需要一个单点修改，区间询问最大值的线段树。 既然只有询问没有修改，那么我们按照询问的人的能力值排个序。确保查询的时候线段树里面只有忠诚值比他大的员工。 对于一个询问，我们需要先查询其dfs序子树区间内忠诚值最大的员工编号，然后将这个员工塞进树里面。 树里面可以存这个员工的忠诚度。由于员工的忠诚度互不相同，得到了最大忠诚度就可以得到这个员工的编号。