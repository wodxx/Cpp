/*********************************************************************
[问题]
  给你一个字符串 s ，请你统计并返回这个字符串中回文子串的数目。
  回文字符串 是正着读和倒过来读一样的字符串。
  子字符串 是字符串中的由连续字符组成的一个序列。
  具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串
**********************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countSubstrings(string s) {
    int len = s.size();
    int sum = 0;

    vector<vector<bool>> dp(len, vector<bool>(len, false));
    for (int i = len - 1; i >= 0; i--) {           //dp[i][j]:i与j区间是否为回文串
      for (int j = i; j < len; j++) {              //注意i和j的遍历顺序
        if (s[i] == s[j]) {
          if (j - i <= 1) {                        //两个数字和一个数字
            sum++;
            dp[i][j] = true;                       //存储这个空间为字符串
          } else if (dp[i + 1][j - 1]) {           //两头相等，如果中间是回文，则sum++
            sum++;
            dp[i][j] = true;                       //对回文串进行存储
          }
        } 
      }
    }

    return sum;
  }
};
 
int main () {

  return 0;
}