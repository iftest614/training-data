---
title: " DTOJ2582Little Elephant and Boxes\t\t"
tags:
  - 折半搜索
url: 734.html
id: 734
categories:
  - DTOJ
  - Solution
date: 2018-02-25 20:01:04
---

发现物品所需的钻石和物品的数量都很小，我们可以先预处理出$f\[i\]\[j\]$，表示用$i$个钻石买到$j$件物品最少需要的钱。这样如果我们知道手上有的钱和钻石数，我们就可以快速知道能买几件物品了。 考虑暴力一点的写法，就是枚举每种手上可能有的钱和钻石数，然后计算答案，大概能通过$n\\leqslant 20$的情况。 发现$n$最大也只有$30$，考虑对暴力进行一下优化。我们可以折半搜索， 把一部分可能有的钱和钻石数先存下来。 然后搜出另一部分中可能有的钱和钻石数，考虑和之间存下的情况组合起来能对答案造成多少贡献。 我们可以枚举存下来的部分中使用的钻石数，和我们最终买的物品数量，然后考虑如何计算出概率。 设当前这部分有$a$个钻石和$c$美元，存下来的部分中使用$b$个钻石。若我们最终买了$x$件商品，还需要的钱$d$需要满足

$f\[a+b\]\[x\]\\leqslant c+d<f\[a+b\]\[x+1\]$

即

$f\[a+b\]\[x\]-c\\leqslant d<f\[a+b\]\[x+1\]-c$

显然$d$的取值是一段区间。 因此我们可以将存下来的部分按照钻石数分类，然后对于每一类按钱的数量排序，并预处理出每一类概率的前缀和。 这样对于搜出的每一种情况就可以很快的计算完对答案的贡献了。