给定如下的正则表达式 (a|b)((c|d)*)，请完成如下练习：
（1）使用Thompson算法，将该正则表达式转换成非确定状态有限自动机（NFA）；

```dot
digraph LR{
  rankdir=LR;
  node [shape = doublecircle];n12;
  node [shape = circle];
  n0->n1[label=epsilon];
  n1->n2[label=a];
  n0->n3[label=epsilon];
  n3->n4[label=b];
  n2->n5[label=epsilon];
  n4->n5[label=epsilon];
  n5->n6[label=epsilon];
  n6->n7[label=epsilon];
  n7->n8[label=c];
  n6->n9[label=epsilon];
  n9->n10[label=d];
  n8->n11[label=epsilon];
  n10->n11[label=epsilon];
  n11->n12[label=epsilon];
  n11->n6[label=epsilon];
  n5->n12[label=epsilon];
}
```
（2）使用子集构造算法，将该上述的非确定有限状态自动机（NFA）转换成确定状态有限自动机（DFA）；
p0{n0,n1,n3}

p0+a = p1{n2,n5,n6,n7,n9,n12}
p0+b = p2{n4,n5,n6,n7,n9,n12}

p1+c = p2+c = p3{n8,n11,n12,n5,n6,n7,n9}
p1+d = p2+d = p4{n10,n11,n12,n5,n6,n7,n9}

p3+c = p3
p3+d = p4

p4+c = p3
p4+d = p4

```dot
digraph LR{
  rankdir=LR
  node [shape = doublecircle];p1,p2,p3,p4;
  node [shape = circle];
  p0->p1[label=a]
  p0->p2[label=b]
  p1->p3[label=c]
  p1->p4[label=d]
  p2->p4[label=d]
  p2->p3[label=c]
  p3->p4[label=d]
  p3->p3[label=c]
  p4->p3[label=c]
  p4->p4[label=d]
}
```
（3）使用Hopcroft算法，对该DFA最小化。
p5 = p3+p4
```dot
digraph LR{
  rankdir=LR
  node [shape = doublecircle];p1,p2,p5;
  node [shape = circle];
  p0->p1[label=a]
  p0->p2[label=b]
  p1->p5[label=b]
  p1->p5[label=c]
  p2->p5[label=b]
  p2->p5[label=c]
  p5->p5[label=b]
  p5->p5[label=c]
}
```
p6 = p1+p2
```dot
digraph LR{
  rankdir=LR
  node [shape = doublecircle];p6,p5;
  node [shape = circle];
  p0->p6[label=a]
  p0->p6[label=b]
  p6->p5[label=c]
  p6->p5[label=d]
  p5->p5[label=b]
  p5->p5[label=c]
}
```
p7 = p5+p6
```dot
digraph LR{
  rankdir=LR
  node [shape = doublecircle];p7;
  node [shape = circle];
  p0->p7[label=a]
  p0->p7[label=b]
  p7->p7[label=c]
  p7->p7[label=d]
}
```
