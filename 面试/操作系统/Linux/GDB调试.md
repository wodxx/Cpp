# GDB调试指南

GDB是Linux下非常好用且强大的调试工具。GDB可以调试C、C++、Go、java、 objective-c、PHP等语言。

## 基本命令的操作

GDB中的命令很多，但我们只需掌握其中十个左右的命令，就大致可以完成日常的基本的程序调试工作。

![tushi](https://img-blog.csdnimg.cn/20200325143501870.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NoZW4xNDE1ODg2MDQ0,size_16,color_FFFFFF,t_70)

gdb命令拥有较多内部命令。在gdb命令提示符“(gdb)”下输入“help”可以查看所有内部命令及使用说明。

![tushi](https://img-blog.csdnimg.cn/2020032514353385.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NoZW4xNDE1ODg2MDQ0,size_16,color_FFFFFF,t_70)

## 判断文件是否带有调试信息

要调试C/C++的程序，首先在编译时，要使用gdb调试程序，在使用gcc编译源代码时必须加上“-g”参数。保留调试信息，否则不能使用GDB进行调试。

有一种情况，有一个编译好的二进制文件，你不确定是不是带有-g参数，带有GDB调试，这个时候你可以使用如下的命令验证：

![tushi](https://img-blog.csdnimg.cn/20200325143628327.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NoZW4xNDE1ODg2MDQ0,size_16,color_FFFFFF,t_70)

如果没有调试信息，则会出现：
>Reading symbols from /home/minger/share/tencent/gdb/main…(no debugging symbols found)…done.

/home/minger/share/tencent/gdb/main是程序的路径。

如果带有调试功能，下面会提示：说明可以进行调试

![tushi](https://img-blog.csdnimg.cn/20200325143728500.png)
>Reading symbols from /home/minger/share/tencent/gdb/main…done.

还有使用命令readlef查看可执行文件是否带有调试功能：

    readelf -S main|grep debug

![tushi](https://img-blog.csdnimg.cn/20200325143856808.png)

如果有debug说明有调试功能，如果没有debug。说明没有带有调试功能，则不能被调试。

## 调试方式启动运行无参程序

以下是linux下GDB调试的一个实例，先给出一个示例用的小程序，C语言代码：
main.c

```C
#include <stdio.h>

void Print(int i){

 printf("hello,程序猿编码 %d\n", i);
}

int main(int argc, char const *argv[]){
  int i = 0;
  for (i = 1; i < 3; i++){
    Print(i);
  }
  return 0;
}
```

编译：

    gcc -g main.c -o main

下面“gdb”命令启动GDB，将首先显示GDB说明，不管它：

![tushi](https://img-blog.csdnimg.cn/20200325144054156.png)

上面最后一行“(gdb)”为GDB内部命令引导符，等待用户输入GDB命令。

下面使用“file”命令载入被调试程序 main（这里的 main 即前面gcc 编译输出的可执行文件）：

如果最后一行提示Reading symbols from /home/minger/share/tencent/gdb/main…done. 表示已经加载成功。

下面使用“r”命令执行（Run）被调试文件，因为尚未设置任何断点，将直接执行到程序结束：

![tushi](https://img-blog.csdnimg.cn/20200325144128924.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NoZW4xNDE1ODg2MDQ0,size_16,color_FFFFFF,t_70)

## 调试启动带参程序

```C
#include <stdio.h>

int main(int argc, char const *argv[]){

  if (1 >= argc){
    printf("usage:hello name\n");
    return 0;
  }

  printf("hello,程序猿编码 %s\n", argv[1]);

 return 0;
}
```

编译

    gcc -g test.c -o test

这种情况如何启动调试呢？只需要r的时候带上参数即可。

![tushi](https://img-blog.csdnimg.cn/20200325144229184.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NoZW4xNDE1ODg2MDQ0,size_16,color_FFFFFF,t_70)

## GDB的底层实现原理

>ptrace()函数的调用

[参考](https://blog.csdn.net/chen1415886044/article/details/105094688?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166165416416782395352994%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=166165416416782395352994&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-105094688-null-null.142^v42^pc_rank_34_1,185^v2^control&utm_term=GDB&spm=1018.2226.3001.4187)
