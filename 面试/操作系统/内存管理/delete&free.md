# malloc/free,new/delete

标准回答 delete 和 free 的区别：

 1. delete 是操作符，而 free 是函数；(本质)

 2. delete 用于释放 new 分配的空间，free 有用释放 malloc 分配的空间；(释放对象不同)

 3. free 不会调用对象的析构函数，而 delete 会调用对象的析构函数；

 4. 调用 free 之前需要检查要释放的指针是否为 NULL，使用 delete 释放内存则不需要检查指针是否为 NULL；
