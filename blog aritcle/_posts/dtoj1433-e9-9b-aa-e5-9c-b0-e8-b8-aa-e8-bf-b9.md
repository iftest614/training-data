---
title: " DTOJ1433雪地踪迹\t\t"
tags:
  - 思路
url: 2000.html
id: 2000
categories:
  - DTOJ
  - Solution
date: 2018-05-17 13:58:35
---

根据题意可知，每次一只动物出现后，都会形成一个包含左上角和右下角的连通块。 由于要求最小出现的动物数目，所以我们要使每只动物走的路尽可能的多，因此肯定是兔子和狐狸轮流出现。不妨假设最后一只出现的动物是狐狸（即左上角和右下角的字符为F）。那么最后一只动物走过的路就是和包含左上角和右下角的最大的F连通块。 接着考虑倒数第二只动物。它可以走最后一只动物走过的路（因为会被覆盖），同时还能走到最后一只动物走过的路旁边的R连通块。 倒数第三只动物同理，可以走最后两只动物走过的路和旁边的F连通块。 因此，我们可以从左上角开始，用bfs遍历当前动物能走的路，即在上一次bfs的基础上遍历F连通块或R连通块。当遍历完整张图后，bfs的次数就是最小出现的动物数目。