# 2018.1.11
完成第一周的课后习题，阅读代码还是花了写时间，对一开始的“TODO”想了会，还以为要用一个宏去实现（笑）。题目的源码是C写的，用了不少struct和enum,看着好费力气，找时间oo写一遍应该会好看很多。题目还要求用不超过十行代码完成，这点上我是没有达到要求的，但并没有去删减代码的意向，毕竟我觉得代码的可读性和逻辑性在大多数情况下(只要没有出现性能瓶颈)是更重要的。
# 2018.1.12
完成第二周的课后习题，与课程的实例相比，这个词法分析器增加了“行”与“列”这两个属性，但整体难度并没有提升。虽然只实现了“if”和其他标识符的识别，但已经可以窥见手写分析器的繁琐了。这次作业的收获是让我发现自己对i/o操作的生疏，接下来要回炉在好好看看书了。
# 2018.1.16
总算是做完第三次作业，相比前两次，我感觉还是难了些的。这次分了三小项作业，让我对词法分析器算是有了一个比较明确的认识，RE如何变成NFA，NFA又怎么成为DFA，DFA最终通过什么手段精简，都一一有了了解（尤其是RE->NFA）。（顺便还发现我第二周作业实现的一个小bug）
# 2018.1.19
第四周作业相对简单，原程序无法识别‘-’和‘/’，因为分别与‘+’和‘\*’是同级的运算符，只要在原本识别‘+’的地方识别‘-’，识别‘\*’的地方识别‘/’就好了。
# 2018.1.25
终于学完第五周的课程辣，感觉好好好好好好好好好好好好好好好好好好难啊。
