# unordered_set

>哈希表是根据关键码值而进行直接访问的数据结构，通过相应的哈希函数(也称散列函数)处理关键字得到相应的关键码值，关键码值对应着一个特定位置，用该位置来存取相应的信息，这样就能以较快的速度获取关键字的信息。哈希函数 f(key) = value。

模板原型：

```C++
template < class Key,
    class Hash = hash<Key>,
    class Pred = equal_to<Key>,
    class Alloc = allocator<Key>
> class unordered_set;
```

在一个unordered_set内部，元素不会按任何顺序排序，而是通过元素值的hash值将元素分组放置到各个槽(Bucker，也可以译为“桶”），这样就能通过元素值快速访问各个对应的元素（均摊耗时为O（1））。
