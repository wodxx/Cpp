/***********************************************************************
[问题]

  给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。
  每步 可以删除任意一个字符串中的一个字符。
*************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    int len1 = word1.size();
    int len2 = word2.size();

    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 0; i <= len1; i++) dp[i][0] = i;                                   //要取到len1和len2
    for (int j = 0; j <= len2; j++) dp[0][j] = j;

    for (int i = 1; i <= len1; i++) {
      for (int j = 1; j <= len2; j++) {
        if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];             //递推式中有i-1时要取到最值即len1和len2
        else dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + 2);
      }                                                                            //两种情况取最小：删一个和两个都删
    }
 
    return dp[len1][len2];
  }
};

int main () {

  return 0;
}