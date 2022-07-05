# C++——cout输出小数点后指定位数

在C++的编程中，总会遇到浮点数的处理，有的时候，我们只需要保留2位小数作为输出的结果，这时候，问题来了，怎样才能让cout输出指定的小数点后保留位数呢？

在C++中，是没有格式符的，我们可以通过使用setprecision()函数来实现这个需求。
想要使用**setprecision()函数**，必须包含头文件#include < iomanip >。使用方式如下：

    cout << "a=" << setprecision(2) << a <<endl;

***setprecision(2)保留两位有效数字，如果是0，则会被舍去。***

举例：如果a的值为0.20001，输出的结果为a=0.2，后面第二位的0被省略了。

如果我们想要让它自动补0，需要在cout之前进行补0的定义(即加fixed)。代码如下：

    cout.setf(ios::fixed);
    cout << "a=" <<fixed<< setprecision(2) << a <<endl; 
    // 此时输出 a = 0.20 

[参考代码]

```C
#include <iostream>
#include <iomanip>
 
using namespace std;
 
int main()
{
    float a = 0.20001;
    cout.setf(ios::fixed);
    cout << "a=" <<fixed<< setprecision(2) << a <<endl; //输出结果为a=0.20
    cout.unsetf(ios::fixed);
    cout << "a=" << setprecision(2) << a <<endl; //输出结果为a=0.2
    return 0;
}
```

[参考](https://blog.csdn.net/edricbjtu/article/details/41082597?spm=1001.2101.3001.6650.3&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-3-41082597-blog-106956204.pc_relevant_aa2&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-3-41082597-blog-106956204.pc_relevant_aa2&utm_relevant_index=6)
