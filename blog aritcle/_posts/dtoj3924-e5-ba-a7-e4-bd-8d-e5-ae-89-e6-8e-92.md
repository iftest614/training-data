---
title: " DTOJ3924座位安排\t\t"
tags:
  - 贪心
url: 4059.html
id: 4059
categories:
  - Solution
date: 2018-09-23 21:13:40
---

处理出每个座位到前门和后门的距离。首先考虑前门的，顺序对于每个妹子，找到一个距离最大的合法的位置然后安排这个妹子。对于没有被安排到的位置丢到一个堆里面维护。那么对于后门的我们就从堆里抓出来一个跟妹子匹配。如果失败就是NO了。