# C++的编译过程

**对于一个基本的程序，由.cpp文件和.h文件组成。且声明一般都放在了头文件中(.h文件)，比如类的声明和一些函数的声明。**

## 预编译

>头文件中有一些带#开头的关键字，如：#define,#ifndef,#endif,等等。

  这阶段是预处理阶段，比如说·#define m 5，那么在该阶段会将**程序中的m全部替换成5**

  条件编译的关键字：

  ***条件编译指令***：#ifdef，#ifndef，#else，#elif，#endif等。不同于程序中的条件指令 if else :

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

**这样可以兼容不同的平台**，想在linux平台下运行，只要在条件编译前添加#define Linux就好了，

>另外，也可以通过这种方式来选择不接入某些不需要用的模块，提高编译速度：

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

如果我们没有在#ifndef USE_Printf之前添加#define USE_Printf,就会编译

那个具体的函数，从而降低了编译速度，而没添加定义USE_Printf的话，就会将

这个函数定义为空，从而提高了编译速度。

>定义与不定义一个类的名字

```C
#define A  animal  //A代表animal

class  A
{
public:
int move;
void out_put();
}
#undef A         //A不再表示animal
```

对比：

```C
void themeat(animal a,animal b,animal* c);

void themeat(A a,A b,A* c);
```

>使用条件函数调用函数

```C
#ifndef  _human_H 
#define _human_H 

#include "animal.h"   //human类 要从animal类 中继承
#include "iostream.h"

class  human: public animal
{
public:
int thought;
}

void showme();//函数声明
#endif
```

假设每一个头文件都是一个函数，每个文件中每#include一个头文件的时候，就相当于调用一次那个函数。

```C
//不用条件函数， 相互调用， 死循环
void animal()
{
static _animal_H=false;
  human()
}
void human()
{
  static _human_H=false;
  animal();        //  #include "animal.h"   
}
```

```C
//使用条件函数
void animal()
{
static _animal_H=false;
if(_animal_H==false)
{
_animal_H=ture;
  human();
}
}

void human()
{
static _human_H=false;
if(_human_H==false)
{
  _human_H=true;

  animal();        //  #include "animal.h"  
} 

//这样我们能保证每个函数只调用一次，而不会相互一直调用
//也正是因为这样，所以我们才能放心大胆的随便 #include：}
```

之所以用函数的运行来举例说明，那是因为每个#include "animal.h"实际上就是用animal.h文件的内容将其替换。#define 的作用是替换单个符号，而#include的作用是将这个#include用其include的头文件进行替换。如果将文件抽象为函数，那么本质上并没有什么太大区别。

## 为什么#include在文件开头

随着文件越来越大，所有的文件在一个文件夹里是不现实的，看上去就特别乱，我们知道，**调用一个函数之前，必须先能找到他的声明**，所以我们**将各种要调用的函数声明打包成头文件**，并将其添加到main函数之前，在预编译过程中，#include将会被其文件内容替换，从而实现将函数声明放在main之前，为main函数中调用打下基础，这就是为什么#include为什么被放在cpp文件的开始部分。

## 预编译的过程

当编辑器里面点击编译时，会出现以下内容：

```C
Compiling...

animal.cpp
human.cpp

...
Linking...

main.exe - 0 error(s), 0 waring(s)
```

这段文字输出事实上已经说明了编译的步骤了
编译器先对工程中三个源文件main.cpp，animal.cpp，human.cpp进行单独编译 (Compiling...)

**在编译时,由预处理器对预处理指令（#include、#define…）进行处理**，在内存中输出翻译单元（就是将include等在源文件上替换了以后产生的临时文件）。
**编译器接受临时文件，将其翻译成包含机器语言**指令的三个目标文件（main.obj、animal.obj、human.obj）

接下去就是链接过程（Linking...），连接器将目标文件和你用到的相关库文件一起链接形成main.exe。
到此，编译也就结束了。

***注意：在编译过程中头文件不参与编译，预编译时进行各种替换以后，头文件就完成了其光荣使命，不再具有任何作用。***

图示编译过程：

![图示编译过程](https://img-blog.csdn.net/20180927202022582?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzMTMzMTM1/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

[参考](https://blog.csdn.net/qq_43133135/article/details/82865618)
