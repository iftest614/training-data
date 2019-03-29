---
title: " DTOJ3833绿菇领主\t\t"
tags:
  - 思路
  - 线段树
url: 2935.html
id: 2935
categories:
  - DTOJ
  - Solution
date: 2018-07-22 11:15:02
---

先考虑序列是$1\\sim n$的排列的情况。这是一个很经典的问题，有很多种做法。 其中一种是这样的。记区间$\[l,r\]$的最大值为$Max$，最小值为$Min$，那么如果有 $$Max-Min=r-l$$ 即$$Max-Min+l=r$$ 区间$\[l,r\]$就是一个连续的区间。 那么我们可以枚举区间右端点$r$，用线段树维护左端点在每个位置时$Max-Min+l$的值，即用两个单调栈分别维护$Max$和$Min$，在单调栈发生变化的时候在线段树上区间修改。 然后线段树同时维护区间最小值和最小值的个数，如果区间最小值$=r$，那么就存在连续的区间，区间个数就是最小值个数。因为如果一个区间不是连续的，$Max-Min+l$一定会$>r$。 这同时是DTOJ3487第三题的做法。 我们现在再来考虑一下此题要怎么写。 记区间$\[l,r\]$为区间内出现次数最多的数的出现次数，那么如果有 $$t(Max-Min+1)=r-l+1$$ 即 $$ tMax-tMin+l-1=r-t $$ 区间$\[l,r\]$就是一个优美的区间。 同样考虑之前的做法，枚举区间右端点$r$，用线段树维护左端点在每个位置时的$tMax-tMin+l-1$的值。 但是我们不知道$t$是多少。 由于每个出现次数$\\leqslant 10$，所以$t\\in\[1,10\]$，我们在线段树上维护$10$个值即可。 查询的时候，由于$t$的影响，我们要将总区间分成$10$个区间查询。也就是说，我们要维护$10$个左端点，第$i$个左端点$l\_i$表示区间$\[l\_i,r\]$的$t=i$，且区间$\[l\_i-1,r\]$的$t=i+1$。 $l\_i$可以很容易地在移动右端点的时候顺便维护。 那么我们依次查询区间$\[l_i,r\]$中$t=i$时的最小值，如果最小值$=r-i$，那么就存在优美的区间，区间个数就是最小值个数。因为如果一个区间不是优美的，$tMax-tMin+l-1$一定会$>r-t$。 右端点从$1$枚举到$n$，就可以求出优美区间的数量了。 时间复杂度$\\Theta(10n\\log n)$。