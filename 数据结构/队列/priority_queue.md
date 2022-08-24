# c++优先队列(priority_queue)

包含头文件 #include< queue >

queue不同的就在于**可以自定义其中数据的优先级, 让优先级高的排在队列前面,优先出队。**

```C
和队列基本操作相同:

top 访问队头元素           //优先队列不是队列，是堆，所以用top（）
empty 队列是否为空
size 返回队列内元素个数
push 插入元素到队尾 (并排序)
emplace 原地构造一个元素并插入队列
pop 弹出队头元素
swap 交换内容
```

定义：

```C
priority_queue<Type, Container, Functional>
```

**Type 就是数据类型，Container 就是容器类型**（Container必须是用数组实现的容器，比如vector,deque等等，但不能用 list。STL里面默认用的是vector），**Functional 就是比较的方式**，当需要用自定义的数据类型时才需要传入这三个参数，使用基本数据类型时，只需要传入数据类型，默认是大顶堆。

优先队列中元素默认按自然顺序排列，也就是**数字默认是小的在队列头，字符串则按字典序排列**.

>自负串字典序： 即给定两个自负串，逐个字符比较， 那么先出现较小字符的串字典序小；如果字符一直想等，则较短的串字典序小。例如： abc < abcd < abde < afab

1.举例：

```C
#include<iostream>
#include <queue>
using namespace std;
int main() 
{
    //对于基础类型 默认是大顶堆
    priority_queue<int> a; 
    //等同于 priority_queue<int, vector<int>, less<int> > a;
    
  
    priority_queue<int, vector<int>, greater<int> > c;  //这样就是小顶堆
    priority_queue<string> b;

    for (int i = 0; i < 5; i++) 
    {
        a.push(i);
        c.push(i);
    }
    while (!a.empty()) 
    {
        cout << a.top() << ' ';
        a.pop();
    } 
    cout << endl;

    while (!c.empty()) 
    {
        cout << c.top() << ' ';
        c.pop();
    }
    cout << endl;

    b.push("abc");
    b.push("abcd");
    b.push("cbd");
    while (!b.empty()) 
    {
        cout << b.top() << ' ';
        b.pop();
    } 
    cout << endl;
    return 0;
}

输出：
4 3 2 1 0
0 1 2 3 4
cbd abcd abc
```

2.pari的比较，先比较第一个元素，第一个相等比较第二个

```C
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() 
{
    priority_queue<pair<int, int> > a;
    pair<int, int> b(1, 2);
    pair<int, int> c(1, 3);
    pair<int, int> d(2, 5);
    a.push(d);
    a.push(c);
    a.push(b);
    while (!a.empty()) 
    {
        cout << a.top().first << ' ' << a.top().second << '\n';
        a.pop();
    }
}

输出：
2 5
1 3
1 2
```

3.对于自定义类型

```C
#include <iostream>
#include <queue>
using namespace std;

//方法1
struct tmp1 //运算符重载<
{
    int x;
    tmp1(int a) {x = a;}
    bool operator<(const tmp1& a) const
    {
        return x < a.x; //大顶堆
    }
};

//方法2
struct tmp2 //重写仿函数
{
    bool operator() (tmp1 a, tmp1 b) 
    {
        return a.x < b.x; //大顶堆
    }
};

int main() 
{
    tmp1 a(1);
    tmp1 b(2);
    tmp1 c(3);
    priority_queue<tmp1> d;
    d.push(b);
    d.push(c);
    d.push(a);
    while (!d.empty()) 
    {
        cout << d.top().x << '\n';
        d.pop();
    }
    cout << endl;

    priority_queue<tmp1, vector<tmp1>, tmp2> f;
    f.push(c);
    f.push(b);
    f.push(a);
    while (!f.empty()) 
    {
        cout << f.top().x << '\n';
        f.pop();
    }
}
输出：
3
2
1

3
2
1
```

[参考](https://blog.csdn.net/weixin_36888577/article/details/79937886?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522165657760116781685370553%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=165657760116781685370553&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-79937886-null-null.142^v26^control,157^v15^new_3&utm_term=priority_queue&spm=1018.2226.3001.4187)
