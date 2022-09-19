// 公共子串与公共子序列的区别：
// 公共子串：字符必须是连续相等的
// 公共子序列：字符必须是相等的，可以不连续

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 题型1：只求公共子序列的长度
class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int len1 = text1.size();
    int len2 = text2.size();

    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
  //dp[i][j]：长度为[0, i - 1]的字符串text1与长度为[0, j - 1]的字符串text2的最长公共子序列为dp[i][j]
    for (int i = 1; i <= len1; i++) {
      for (int j = 1; j <= len2; j++) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {                                     
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);               
        }     // 最长公共子串与最长公共子序列的区别：后者在两串当前值不等时当前的最长长度为前一个
      }       // 而前者如果不相等 直接进入下一次循环，相等时才记录
    }

    return dp[len1][len2];
  }
};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 题型2：求出公共子序列
// 给定两个字符串str1和str2，输出两个字符串的最长公共子序列。
// 如果最长公共子序列为空，则返回"-1"。目前给出的数据，仅仅会存在一个最长的公共子序列

class Solution {
public:
  string LCS(string s1, string s2) {
    int len1 = s1.size();
    int len2 = s2.size();
    string result;
  // 先计算长度
  // dp[i][j]的含义是i和j【之前】的公共子串的长度，
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 1; i <= len1; i++) {
      for (int j = 1; j <= len2; j++) {
        if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
        else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  // 返回遍历求最长子串
    for (int i = len1, j = len2; dp[i][j] >= 1;) {
      if (s1[i - 1] == s2[j - 1]) {
        result += s1[i - 1];
        --i;
        --j;
      } 
      else if (dp[i - 1][j] >= dp[i][j - 1]) --i;
      else --j;  
    }
    reverse(result.begin(), result.end());
    return result.size() == 0 ? "-1" : result;
  }
};

// 最长公共子序列要注意的问题：
// 1.从1开始遍历，到等于字符串的size结束，注意递推式
// 2.不用保留最大值，求长度最后直接返回dp[size1][size2];
// 3.逆序遍历求子串从等于size开始，到等于1结束，分为三种情况;
// 4.反转求出的字符串后输出


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 题型3：求最长公共子串
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




int main() {

  return 0;
}