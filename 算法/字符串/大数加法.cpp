// 描述
// 以字符串的形式读入两个数字，编写一个函数计算它们的和，以字符串形式返回。

// 数据范围：s.length,t.length \le 100000s.length,t.length≤100000，字符串仅由'0'~‘9’构成
// 要求：时间复杂度 O(n)O(n)

// 输入：
// "1","99"
// 返回值：
// "100"
// 说明：
// 1+99=100   

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string solve(string s, string t) {
  // 逐位加法 计算进位 保存进位值
    int sumsub = 0;                                          // 保存进位值
    string result;
    int i = s.size() - 1, j = t.size() - 1;
    while (i >= 0 && j >= 0) {
      int sum = s[i] + t[j] - '0' + sumsub - '0';
      result = result.insert(0, 1, sum % 10 + '0');          // 在该字符串0的位置插入一个字符 sum % 10 +'0'
      sumsub = sum / 10;
      --i, --j;
    }
    while (i >= 0) {
      int sum = s[i] + sumsub - '0';                         // 如果低位还有进位 要加
      result = result.insert(0, 1, sum % 10 + '0');
      sumsub = sum / 10;
      --i;
    }
    while (j >= 0) {
      int sum = t[j] + sumsub - '0';
      result = result.insert(0, 1, sum % 10 + '0');
      sumsub = sum / 10;
      --j;
    }
    if (sumsub != 0) result = result.insert(0, 1, sumsub + '0');
    return result;
  }
};

int main () {

  return 0;
}