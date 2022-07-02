# 双向队列deque

所谓的deque是”double ended queue”的缩写，双端队列不论在尾部或头部插入元素，都十分迅速。而在中间插入元素则会比较费时，因为必须移动中间其他的元素。**双端队列是一种随机访问的数据类型，提供了在序列两端快速插入和删除操作的功能**，它可以在需要的时候改变自身大小，完成了标准的C++数据结构中队列的所有功能。

## 声明deque容器

```C
#include<deque>  // 头文件
deque<type> deq;  // 声明一个元素类型为type的双端队列que
deque<type> deq(size);  // 声明一个类型为type、含有size个默认值初始化元素的的双端队列que
deque<type> deq(size, value);  // 声明一个元素类型为type、含有size个value元素的双端队列que
deque<type> deq(mydeque);  // deq是mydeque的一个副本
deque<type> deq(first, last);  // 使用迭代器first、last范围内的元素初始化deq
```

## deque的常用成员函数

```C
deq[ ]：用来访问双向队列中单个的元素。
deq.front()：返回第一个元素的引用。
deq.back()：返回最后一个元素的引用。
deq.push_front(x)：把元素x插入到双向队列的头部。
deq.pop_front()：弹出双向队列的第一个元素。
deq.push_back(x)：把元素x插入到双向队列的尾部。
deq.pop_back()：弹出双向队列的最后一个元素。
```

## deuqe的一些特点

```C
支持随机访问，即支持[ ]以及at()，但是性能没有vector好。
可以在内部进行插入和删除操作，但性能不及list。
deque两端都能够快速插入和删除元素，而vector只能在尾端进行。
deque的元素存取和迭代器操作会稍微慢一些，因为deque的内部结构会多一个间接过程。
deque迭代器是特殊的智能指针，而不是一般指针，它需要在不同的区块之间跳转。
deque可以包含更多的元素，其max_size可能更大，因为不止使用一块内存。
deque不支持对容量和内存分配时机的控制。
在除了首尾两端的其他地方插入和删除元素，都将会导致指向deque元素的任何pointers、references、iterators失效。不过，deque的内存重分配优于vector，因为其内部结构显示不需要复制所有元素。
deque的内存区块不再被使用时，会被释放，deque的内存大小是可缩减的。不过，是不是这么做以及怎么做由实际操作版本定义。
deque不提供容量操作：capacity()和reverse()，但是vector可以。
```

## 举例

```C++
#include<iostream>
#include<stdio.h>
#include<deque>
using namespace std;
int main(void)
{
int i;
int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
deque<int> q;
for (i = 0; i <= 9; i++)
{
  if (i % 2 == 0)
    q.push_front(a[i]);
  else
    q.push_back(a[i]);
}                                  /*此时队列里的内容是: {8,6,4,2,0,1,3,5,7,9}*/
q.pop_front();
printf("%d\n", q.front());    /*清除第一个元素后输出第一个(6)*/
q.pop_back();
printf("%d\n", q.back());     /*清除最后一个元素后输出最后一个(7)*/
deque<int>::iterator it;
for (it = q.begin(); it != q.end(); it++) {
  cout << *it << '\t';
}
cout << endl;
system("pause");
return 0;
}
```

[参考](https://blog.csdn.net/qq_41078889/article/details/108054978?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522165675810216781818765771%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=165675810216781818765771&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-4-108054978-null-null.142^v30^control,185^v2^control&utm_term=deque&spm=1018.2226.3001.4187)
