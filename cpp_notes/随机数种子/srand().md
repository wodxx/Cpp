<!--
 * @Author: your name
 * @Date: 2021-10-20 20:48:26
 * @LastEditTime: 2021-10-20 21:25:53
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: /Cpp/cpp_notes/随机数种子/srand().md
-->
# 随机数 #

## rand() ##

功能:随机数发生器
所在头文件: stdlib.h
>rand()返回的随机数在范围0至RAND_MAX之间。RAND_MAX的范围最少是在32767之间(int)
>用户未设定随机数种子时，系统默认的随机数种子为1.
>rand()产生的时伪随机数，每次执行是相同的；若要不同需用函数srand()初始化它。

## 二.srand() ##

功能:初始化随机数发生器
头文件:stdlib.h
>srand()用来设置rand()产生随机数时的随机数种子。
>参数seed必须是个整数，通常可以利用time(0)的返回值或NULL来当做seed。
>如果每次seed都设相同值，rand()所产生的随机数值每次就会一样。

## 三.rand()和srand()的关系 ##

**rand()和srand()要一起使用，其中srand()用来初始化随机数种子,rand()用来产生随机数。**

>因为默认情况下随机数种子为1，而相同的随机数种子产生的随机数是一样的,失去了随机性的意义，
所以为使每次得到的随机数不一样，用函数srand()初始化随机数种子。srand()的参数，用time函数值（即当前时间），
因为两次调用rand()函数的时间通常是不同的，这样就可以保证随机性了。
