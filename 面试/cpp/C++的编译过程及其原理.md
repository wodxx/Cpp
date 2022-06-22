# C++的编译过程

**对于一个基本的程序，由.cpp文件和.h文件组成。且声明一般都放在了头文件中(.h文件)，比如类的声明和一些函数的声明。**

1. 预编译

  头文件中有一些带#开头的关键字，如：#define,#ifndef,#endif,等等。

  这阶段是预处理阶段，比如说·#define m 5，那么在该阶段会将程序中的m全部替换成5

  条件编译的关键字：

  ***条件编译指令***：#ifdef，#ifndef，#else，#elif，#endif等。不同程序中的条件指令 if else :

  **程序中的条件选择是在程序运行的时候才被执行的，而条件编译是在预编译时执行的条件选择。**

```C
#ifdef  Linux
linux平台下运行的函数
#else
#ifdef  windows
Windows平台下运行的函数
#endif       
#endif
```

这样可以兼容不同的平台，想在linux平台下运行，只要在条件编译前添加#define Linux就好了，

另外，也可以通过这种方式来选择不接入某些不需要用的模块，提高编译速度：

```C
#ifndef  USE_Printf  //如果没有定义USE_Printf
#define myPrintf(...)    //定义为空（无内容）
#else
void myPrintf(....) //定义为一个具体函数
{
......
}           
#endif
```
