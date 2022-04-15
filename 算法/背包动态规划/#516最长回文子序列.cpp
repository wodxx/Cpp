#include <bits/stdc++.h>
using namespace std;

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

int main () {

  return 0;
}