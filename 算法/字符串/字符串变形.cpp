// 描述
// 对于一个长度为 n 字符串，我们需要对它做一些变形。

// 首先这个字符串中包含着一些空格，就像"Hello World"一样，然后我们要做的是把这个字符串中由空格隔开的单词反序，同时反转每个字符的大小写。

// 比如"Hello World"变形后就变成了"wORLD hELLO"。

// 输入：
// "This is a sample",16

// 返回值：
// "SAMPLE A IS tHIS"

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string trans(string s, int n) {
    string result, temp;
    if (n == 0) return result;
    for (int i = 0; i < n; i++) {
      if (s[i] != ' ') temp += s[i];                      // 临时字符串为一个完整的单词
      else result = ' ' + temp + result, temp.clear();    // 调整顺序也就是先加temp和空格而已
    }
    if (!temp.empty()) result = temp + result;            // 最后的单词不用加空格
    for (int i = 0; i < result.size(); i++) {             // 大小写转换
      if (result[i] <= 'z' && result[i] >= 'a') result[i] = toupper(result[i]);
      else if (result[i] <= 'Z' && result[i] >= 'A') result[i] = tolower(result[i]);
    }
    return result;
  }
};

int main () {

  return 0;
}