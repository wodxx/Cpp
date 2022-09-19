#include <bits/stdc++.h>
using namespace std;

// 最长回文子序列 LC516
// 区别于最长回文子串
class Solution {
public:
  int longestPalindromeSubseq(string s) {
    int len = s.size();
    vector<vector<int> > dp(len + 1, vector<int>(len + 1, 0));  //初值为0（可能为空字符串，即无子序列）
    
    //dp[i][j]表示i到区间j之间的回文子序列长度
    for (int i = 0; i < len; i++) dp[i][i] = 1;
    for (int i = len - 1; i >= 0; i--) {                        //注意i和j开始的位置
      for (int j = i + 1; j < len; j++) {
        if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;      //两端相同则长度+2
        else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);        //不同则取两端分别为端点时的最大值
      }
    }

    return dp[0][len - 1];                                      //返回这个区间
  }
};

// 最长回文子序列和最长回文子串的区别：
// 首先是子序列和子串的本质区别；
// 其次是子序列和子串最后的更新不同，子序列是和前一个索引值的结果做取舍，子串是保留历史最值。

// 最长回文子串
class Solution {
public:
  int getLongestPalindrome(string A) {
    int result = 0;
    vector<vector<int>> dp(A.size(), vector<int>(A.size(), 0));
    for (int i = 0; i < A.size(); i++) {
      dp[i][i] = 1;
      result = 1;
    }
    for (int i = A.size() - 1; i >= 0; i--) {
      for (int j = i + 1; j < A.size(); j++) {
        if (A[i] == A[j] && (dp[i + 1][j - 1] != 0  // 用0来判断是否内部是回文，顺便处理aa问题
          || i + 1 >= j - 1)) dp[i][j] = dp[i + 1][j - 1] + 2;
        if(result < dp[i][j]) result = dp[i][j];   // 更新
      }
    }
    return result;
  }
};

int main () {

  return 0;
}