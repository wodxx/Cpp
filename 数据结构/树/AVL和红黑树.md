# 红黑树与平衡二叉树

## 红黑树(RBTree)

红黑树的性质：

红黑树是一棵二叉搜索树，它在每个节点增加了一个存储位记录节点的颜色，可以是RED,也可以是BLACK；通过任意一条从根到叶子简单路径上颜色的约束，红黑树保证最长路径不超过最短路径的二倍，因而近似平衡。

具体性质如下：

- 每个节点颜色不是黑色，就是红色

- 根节点是黑色的

- 如果一个节点是红色，那么它的两个子节点就是黑色的（没有连续的红节点）

- 对于每个节点，从该节点到其后代叶节点的简单路径上，均包含相同数目的黑色节点

![rutu](https://img-blog.csdn.net/20180710091212319?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3RhbnJ1aTUxOTUyMQ==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

你的最短路径就是全黑节点，最长路径就是一个红节点一个黑节点，最后黑色节点相同时，最长路径刚好是最短路径的两倍.

## 平衡二叉树(AVLTree)

平衡二叉树定义(AVL)：它或者是一颗空树，或者具有以下性质的二叉排序树：它的左子树和右子树的深度之差(平衡因子)的绝对值不超过1，且它的左子树和右子树都是一颗平衡二叉树。

一棵AVL树有如下必要条件：

条件一：它**必须是二叉查找树**。

条件二：每个节点的左子树和右子树的高度差至多为1。

![rutu](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9pbWFnZXMyMDE4LmNuYmxvZ3MuY29tL2Jsb2cvMTMwMzAzOS8yMDE4MDUvMTMwMzAzOS0yMDE4MDUyMzE5MDQ0NjQ0Mi03OTIzMzk1NTcucG5n?x-oss-process=image/format,png)

图一中左边二叉树的节点45的左孩子46比45大，不满足二叉搜索树的条件，因此它也不是一棵平衡二叉树。
右边二叉树满足二叉搜索树的条件，同时它满足条件二，因此它是一棵平衡二叉树。

![tu2](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9pbWFnZXMyMDE4LmNuYmxvZ3MuY29tL2Jsb2cvMTMwMzAzOS8yMDE4MDUvMTMwMzAzOS0yMDE4MDUyMzE5MDU0ODQ3OS0zMDMwNjQ0NDcucG5n?x-oss-process=image/format,png)

左边二叉树的节点45左子树高度2，右子树高度0，左右子树高度差为2-0=2，不满足条件二；右边二叉树的节点均满足左右子树高度差至多为1，同时它满足二叉搜索树的要求，因此它是一棵平衡二叉树。

AVL树的查找、插入、删除操作在平均和最坏的情况下都是O（logn），这得益于它时刻维护着二叉树的平衡。如果我们需要查找的集合本身没有顺序，在频繁查找的同时也经常的插入和删除，AVL树是不错的选择。不平衡的二叉查找树在查找时的效率是很低的。

[参考](https://blog.csdn.net/isunbin/article/details/81707606?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522165873808716781667857639%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=165873808716781667857639&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-81707606-null-null.142^v33^pc_rank_34,185^v2^control&utm_term=%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91&spm=1018.2226.3001.4187)

