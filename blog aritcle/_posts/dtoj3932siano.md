---
title: " DTOJ3932siano\t\t"
tags:
  - 线段树
url: 4033.html
id: 4033
categories:
  - Solution
date: 2018-09-23 12:48:45
---

将所有的$A_i$按照从大到小的顺序排序。

那么每一秒，所有草上面会增加一个类似于这样的图形。

![](http://www.dtenomde.com/wp-content/uploads/2018/09/捕获-1.png)

总而言之，它是单调减的。

那么假设原来是一个常函数，它加上这个玩意以后是单调减的。两个单调减的加起来还是单调减的。

即使割掉了一刀，变成了这样：

![](http://www.dtenomde.com/wp-content/uploads/2018/09/捕获-2.png)

我们加上一个单调减的东西以后，这个东西肯定会从单调不增的变成单调减的。

于是，我们每次加上$(d-lastd)*a\_i$以后，都可以用线段树二分来找到一个位置pos，满足在pos及之前，有$sum\_i \\geq b_i$。这一部分就是我们要割掉的草了。

然后我们可以用区间赋值来改掉$sum_i$。

于是这棵线段树就是要支持区间覆盖，区间修改，查询区间和，查询左端点的值并二分四个操作。线段树可以直接解决。