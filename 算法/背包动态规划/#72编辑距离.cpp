/**************************************************************
[问题]
  给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数。
  你可以对一个单词进行如下三种操作：
  1.插入一个字符
  2.删除一个字符
  3.替换一个字符
****************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    int len1 = word1.size();
    int len2 = word2.size();
    
    //dp[i][j]表示下标为i的word1和为j的word2对应的编辑距离
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 0; i <= len1; i++) dp[i][0] = i;                               //word2为空字符串
    for (int i = 0; i <= len2; i++) dp[0][i] = i;                               //word1为空字符串

    for (int i = 1; i <= len1; i++) {
      for (int j = 1; j <= len2; j++) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];                       
        } else {                                                                //word1增、删、换三种情况取最小
          dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
        }                                                                       //三者取最值加{}
      }
    }

    return  dp[len1][len2];
  }
};

int main () {

  return 0;
}

