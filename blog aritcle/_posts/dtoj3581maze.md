---
title: " DTOJ3581maze\t\t"
tags:
  - 思路
url: 1230.html
id: 1230
categories:
  - DTOJ
  - Solution
date: 2018-03-24 21:57:00
---

$40$分比较好想。 对于起点，先三个方向都走一遍，询问找出它的父亲，然后走到父亲上。 那么现在对于我们所在的位置，我们只有两条未知的边，一条往父亲，一条往儿子。 随便选一条边走，然后询问，就知道这条边是往哪的，同样知道另一条边往哪的了。 因此询问一次就可以往上走一步。 考虑更优秀的做法。 记当前深度为$deep$。对于两条未知的边，随便走一条，走完再随便走一条边，然后询问。 可能的结果有$3$种：$deep+2,deep,deep-2$。分情况讨论

1.  $deep+2$，一定是往下走了两步，那么我们知道第一步要往哪里走了，这样可以走到$deep-1$。
2.  $deep$，是往上走了一步再往下走了一步，那我们就知道从$deep-1$往$deep-2$要走哪条边了，可以走到$deep-2$。
3.  $deep-2$，连续往上走了两步，不知道接下来怎么走，因此只能停在$deep-2$。

算一下每种情况的概率。 第一种概率$\\frac{1}{2}$，第二种和第三种概率为$\\frac{1}{4}$。 那么我们每次询问后期望往上走的步数是$\\frac{3}{2}$，当初始深度为$10^5$时期望询问次数是$7.5\\times 10^4$。虽然优秀了一点，但还不够。 接着考虑随便走三步。同样的分析后发现每次询问后期望向上走的步数是$\\frac{7}{4}$。仍然不够。 发现期望步数不断增大。到随便走六步的时候，期望是$\\frac{63}{32}$，差不多已经卡到了满分，这个时候就可以靠脸了。 但我脸黑，随便测了几组都过不了。于是我就改成了每次随便走七步，过了。 其实可以走九步更稳妥。走十步的话移动次数就会超过$10^6$了。