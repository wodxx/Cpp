// [题目] 字符串匹配。给你两个字符串，寻找其中一个字符串是否包含另一个字符串，如果包含，返回包含的起始位置。


// 解1 BF(暴力匹配)算法
// BF(Brute Force)算法，又叫暴力匹配算法或者朴素匹配算法，思路很简单：
// 在主串中取前下标为[0,m-1]这m个字符的子串和模式串逐个字符逐个字符比较，
// 如果完全一样就结束并返回下标；如果有不一样的，那么主串中的子串后移一位，主串中[1,m]这个子串和模式串继续比较，… ，
// 主串中[n-m,n-1]这个子串和模式串继续比较。主串中长度为m的子串有n-m+1个。

#include <bits/stdc++.h>
using namespace std;

int main () {
  string str, mod;
  cin >> str >> mod;
  int len1 = str.size();
  int len2 = mod.size();
  int result = -1;
  for (int i = 0; i < len1 - len2 + 1; i++) {
    int j;
    for (j = 0; j < len2; j++) {                       // 主串与模式串不一致则结束该区间的对比
      if (str[i + j] != mod[j]) break;
    }
    if (j == len2) result = i;
  }
  cout << result << endl;
  return 0;
}

// 最坏的情况下，在第一个for循环里，i 从0到n-m走满共n-m+1次，第二个for循环里，
// j 从0到m-1走满共m次，因此最坏的情况下时间复杂度为O(n*m)，举个例子，
// 在bbbbbbf中查找bf，所有n-m+1个子串都要走完，并且每次和模式串比较都要比较m次，总共比较n-m+1次。
// BF算法最大的优点就是简单，代码不容易出错，在主串和模式串的长度都不大的时候还是比较实用的。
