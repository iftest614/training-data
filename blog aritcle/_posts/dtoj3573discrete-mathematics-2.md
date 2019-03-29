---
title: " DTOJ3573Discrete Mathematics\t\t"
tags:
  - 无标签
url: 1795.html
id: 1795
categories:
  - Solution
date: 2018-04-29 20:48:10
---

大概就是给定平面上的n条直线，然后对于直线之间的交点染色，要求同一条直线上的相邻交点颜色不同，问最少用几种颜色。 这题初看感觉很不可写的样子。但是仔细观察便会发现，线段相交所构成的封闭图形，最小的便是三角形。而由于线段相交的性质，对于一个点，其出边最多为2-3条。并且除了斜率仅有两种的情况，其他的情况均只需要三种颜色即可完成。那么我们只需要计算斜率的个数，然后特判输出，没了...