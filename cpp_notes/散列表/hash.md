# hash

***散列表***

>散列技术是在记录的存储位置和它的关键字之间建立一个确定的对应关系f，使得每个关键字key对应一个存储位置f(key)，adr = f(key)。查找时，根据这个确定的对应关系找到给定值key的***映射***f(key)，若查找集合中存在这个记录，则必定在f(key)的位置上。我们把这种对应关系f称为散列函数，又称为哈希函数（Hash）。按这个思想，采用散列技术将记录存储在一块连续的存储空间中，**这块连续的存储空间称为散列表或哈希表（Hash table）。关键字对应的记录存储位置称为散列地址。**

## 1. Map

映射是指两个集合之间的元素的相互对应关系。 在 C++ 中我们常用的映射是 map。
**map的特点是增加和删除节点对迭代器的影响很小。对于迭代器来说，可以修改实值，而不能修改key**

>构造映射

在C++中，我们构造一个 map 的语句为:

```C
map<T1,T2> m;
```

这样我们定义了一个名为 m 的从 T1 类型到 T2 类型的映射。初始的时候 m 是空映射。

>插入映射

插入有三种方法：

采用创建pair的形式插入pair<string, string>("string", "字符串")

采用make_pair的形式进行插入make_pair("apple", "苹")

采用大括号的形式进行插入{ "left", "左边" }

**通过 insert( ) 方法向集合中插入一个新的映射，参数是一个 pair 类型的结构。这里需要用到另外一个 STL 模板 -元组(pair)。**

```C
map<string, int> dict;  // {}
dict.insert(pair<string, int>("Tom", 1)); // {"Tom"->1}
dict.insert(pair<string, int>("Jone", 2)); // {"Tom"->1, "Jone"->2}
 
dict.insert(pair<string, string>("string", "字符串"));//模板类型pair：构造了一个匿名对象插入到map
dict.insert(make_pair("apple", "苹果"));//模板函数make_pair：偷懒了，实际调的是pair
dict.insert({ "left", "左边" });//map和set常用这种插入方式，insert
dict.insert({ "left", "剩余" });//插入不进去了，因为key值已经有了
```

>访问映射

访问映射合，**直接用 [] 就能访问**。比如 dict[“Tom”] 就可以获取 “Tom” 的班级了。而这里有一个比较神奇的地方，如果没有对 “Tom” 做过映射的话，此时你访问 dict[“Tom”] ，系统将会自动为 “Tom” 生成一个映射，其 value 为对应类型的默认值。并且我们可以之后再给映射赋予新的值，比如 dict[“Tom”] = 3 ，这样为我们提供了另一种方便的插入手段。

```C
map<string, int> dict;  // {}
dict["Tom"] = 1; // {"Tom"->1}
dict["Mary"] = 1; // {"Tom"->1, "Mary"->1}

printf("Mary is in class %d\n", dict["Mary"]);
```

>查找关键字

***count()***

在 C++ 中，查找关键字是否被映射过，可以直接用 count( ) 方法。使用count，返回的是被查找元素的个数。如果有，返回1；否则，返回0。注意，map中不存在相同元素(Tom,Mary)，所以返回值只能是1或0。

***find()函数***

 find函数，返回的是被查找元素的位置，没有则返回map.end()。**注意：map.end()不指向最后一个元素，而指向最后一个元素再+1**，当find不到输入的元素时候，返回迭代器就指向这个end()。

```C
int main(){
    map<string,int> test;
    test.insert(make_pair("test1",1));   //test["test1"]=1
    test.insert(make_pair("test2",2));   //test["test2"]=2
    map<string,int>::iterator it=test.find("test0");
    
    if(it==test.end())
        cout<<"test0 not found"<<endl;
    else
        cout<<it->second<<endl;  //second表示值，即f(key)
   
    cout<<test.count("test1")<<endl;
 
    it=test.find("test1");
    if(it==test.end())
        cout<<"test1 not found"<<endl;
    else
        cout<<it->second<<endl;

//输出：输出： test0 not found    1    1
```

>遍历映射

通过迭代器可以访问映射中的每个映射，每个迭代器的 first 值对应key，second值对应value。

```C
for (map<string, int>::iterator it = dict.begin(); it != dict.end(); ++it) 
    cout << it->first << " is in class " << it->second << endl;
```

>其他

erase | 删除关键字
-|-
size | 获取映射个数
clear | 清空std::map 就是以key来查找value而设计，根据key排序。

```C
    //list=[5,14,34,22,39,5];
map<int, int> map1;
        for (int i=0; i<list.size(); i++){
            map1[i] = list[i];  //此时map里面key是i，即index，而值为map1[1]
        }
        //另外的遍历map的写法
        //for(auto it = m.begin(); it != m.end(); ++it)
        for (map<int, int>::iterator i = map1.begin(); i != map1.end(); i++){
            cout << i->first << ' ' << i->second << endl;
            //map中值的表示方法为it->second
        }
        if (map1.find(3) != map1.end()) {
            cout << "find key=" << map1.find(3)->first << ", value=" << map1.find(3)->second << endl;
        }
        if (map1.count(5) > 0) {
            cout << "count 5: " << map1.count(5) << endl;   //最后一个5的index为 6则映射不到map1里面，故count 1个5
        }

   //输出：
    0 5
    1 14
    2 34
    3 22
    4 39
    5 5
    find key=3, value=22
    count 5:   1
```

## 2. unordered_map

>std::unordered_map 就是以key来查找value而设计,不会根据key排序。其实现使用了哈希表。

对比：

unordered_map和map类似，都是存储的key-value的值，可以通过key快速索引到value。**不同的是unordered_map不会根据key的大小进行排序**，存储时是根据key的hash值判断元素是否相同，即unordered_map内部元素是无序的，而map中的元素是按照二叉搜索树存储，进行中序遍历会得到有序遍历。

unordered_map可类比于Python中的字典。其实现使用了哈希表，可以以O(1)的时间复杂度访问到对应元素，但缺点是有较高的额外空间复杂度。与之对应，STL中的map对应的数据结构是红黑树，红黑树内的数据时有序的，在红黑树上查找的时间复杂度是O(logN)，相对于unordered_map的查询速度有所下降，但额外空间开销减小。

***结论：如果需要内部元素自动排序，使用map，不需要排序使用unordered_map***

## 3. set

 set作为一个容器也是用来存储同一数据类型的数据类型，并且能从一个数据集合中取出数据，在set中每个元素的值都唯一，而且系统能根据元素的值自动进行排序，set的元素不像map那样可以同时拥有实值(value)和键值(key),set元素的键值就是实值。set不允许两个元素有相同的键值。***C++的标准库中的集合支持高效的插入、删除和查询操作，这三个操作的时间复杂度都是 O(lgn)，其中n是当前集合中元素的个数***。如果用数组，虽然插入的时间复杂度是 O(1)，但是删除合查询都是 O(n)，此时效率太低。在C++中我们常用的集合是set。std::set 是基于hash表的，因此并不是顺序存储。

**我们构造set集合的目的是为了快速的检索，不可直接去修改键值。可以先删后插**。

>1、构造一个集合

```C
set<T> s;
```

定义了一个名为s的、储存T类型数据的集合，其中T是集合要储存的数据类型。初始的时候s是空集合。

>插入元素

用 insert( ) 方法向集合中插入一个新的元素。注意如果集合中已经存在了某个元素，再次插入不会产生任何效果，集合中是不会出现重复元素的。

```C
set<string> country;  // {}
country.insert("China"); // {"China"}
country.insert("America"); // {"China", "America"}
```

>删除元素

```C
country.erase("America"); // {"China"}
```

>查找元素

  1.想知道某个元素是否在集合中出现，可以直接用 count( ) 方法--返回某个值元素的个数，如果集合中存在我们要查找的元素，返回 1 ，否则返回 0 。

  2.另一种方法是：find()--返回一个指向被查找到元素的迭代器

```C
// list=[5,14,34,22,39,5];

set<int> set;
        for (int i=0; i<list.size(); i++){
            set.insert(list[i]);
        }
        for (auto i = set.begin(); i != set.end(); i++) {
            cout << *i << endl;
        }

//输出：5 14 22 34 39
```

```C
cout << set.count(5) << endl;
if(set.find(5) != set.end()) 
    cout << *set.find(5) << endl;

//输出： 1   5
```

>遍历集合

```C
 for (set<string>::iterator it = country.begin(); it != country.end(); ++it) 
        cout << (*it) << endl;
```

注意：在C++中遍历set是从小到大进行的。

>其他

方法 | 功能
-|-
begin() | 返回set容器的第一个元素
erase() | 删除一个元素
end() | 返回set容器的最后一个元素
size() | 获取元素的个数
clear() | 清空

[参考](https://www.cnblogs.com/omelet/p/6627667.html)

## 4. unordered_set

std::unordered_set 是基于hash表的，因此并不是顺序存储。

```C
// list=[5,14,34,22,39,5];
 unordered_set<int> set;
        for (int i=0; i<list.size(); i++){
            set.insert(list[i]);
        }
        for (unordered_set<int>::iterator i = set.begin(); i != set.end(); i++) {
            cout << *i << endl;
        }
        cout << " find 39: " << *set.find(39) << endl;
        cout << "count 14:" << set.count(5) << endl;
//输出：
22
39
34
14
5
 find 39: 39
count 14: 1
```

## 总结

>unordered_map和map：

**unordered_map存储机制是哈希表**。unordered_map不会根据key的大小进行排序，存储时是根据key的hash值判断元素是否相同，即unordered_map内部元素是无序的。

**map是红黑树，红黑树内的数据时有序的，里面的元素可以根据键进行自动排序**。map中的元素是按照二叉搜索树存储，进行中序遍历会得到有序遍历。

***如果需要内部元素自动排序，使用map，不需要排序使用unordered_map***

>unordered_set和set：

**unordered_set基于哈希表，是无序的。**

**set实现了红黑树的平衡二叉检索树的数据结构**，插入元素时，它会自动调整二叉树的排列，把元素放到适当的位置，以保证每个子树根节点键值大于左子树所有节点的键值，小于右子树所有节点的键值；另外，还得保证根节点左子树的高度与右子树高度相等。平衡二叉检索树使用中序遍历算法，检索效率高于vector、deque和list等容器，另外使用中序遍历可将键值按照从小到大遍历出来。

>set和map的区别：

1.set里面每个元素只存有一个key值，它支持高效的关键字查询操作，比如检查一个关键字是否在set中。如果这个key值之前存在的话就不插入。

```C
set<int> s;
s.insert(2);
s.insert(1);
s.insert(4);
s.insert(5);
s.insert(3);
s.insert(5);
s.insert(5);
for (auto e : s)
cout << e << " ";
```

打印出来的值为1 2 3 4 5。**set容器自动对以上数据进行了排序，并且实现了去重**。但是不能对set里的值进行修改，set容器中的find查找效率高，因为底层是一个二叉搜索树，比要查找的值小就去左子树查找，反之则去右子树查找。

2.map是一种key(键),value(值)的形式，用来保存键和值组成的集合，键必须是唯一的，但值可以不唯一。里面的元素可以根据键进行自动排序，由于map是key_value的形式，所以map里的所有元素都是pair类型。pair里面的first被称为key(键），second被称为value(值)。它可以通过关键字key查找映射关联信息value，同时根据key值进行排序。

set和map都以RBTree作为底层容器。

***set：***

  所得元素的只有key没有value，value就是key

  不允许出现键值重复

  所有的元素都会被自动排序

  不能通过迭代器来改变set的值，因为set的值就是键

***map：***

map的值不作为键，键和值是分开的，所有元素都是键+值存在

不允许键重复

所有元素是通过键进行自动排序的

map的键是不能修改的，但是其键对应的值是可以修改的

[参考](https://blog.csdn.net/ETalien_/article/details/89439892)
