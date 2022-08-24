// 描述
// 给定两个字符串str1和str2,输出两个字符串的最长公共子串
// 题目保证str1和str2的最长公共子串存在且唯一。 

// 输入：
// "1AB2345CD","12345EF"
// 返回值：
// "2345"

// 区别于 最长公共子序列

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string LCS(string str1, string str2) {
    int len1 = str1.size();
    int len2 = str2.size();
    int maxnum = 0;
    int maxindex = 0;
    vector<vector<int>> dp(len1 + 1, vector<int> (len2 + 1, 0));
    for (int i = 1; i <= len1; i++) {
      for (int j = 1; j <= len2; j++) {
        if (str1[i - 1] == str2[j - 1])              // 只有当两个串的字符相等
          dp[i][j] = dp[i - 1][j - 1] + 1;
        if (dp[i][j] > maxnum) {                     // 公共子串的长度 发生变化
          maxnum = dp[i][j];                         // 公共子串的最大索引maxlength
          maxindex = i;
        }
      }
    }                                                // 原字符串中截取该段公共子串
    return str1.substr(maxindex - maxnum, maxnum);    
  }
};

int main () {

  return 0;
}

