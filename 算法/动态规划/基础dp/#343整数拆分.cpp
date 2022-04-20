/********************************************************************************
给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
返回 你可以获得的最大乘积 。
********************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int integerBreak(int n) {
    vector<int>dp(n + 1, 0);
    dp[2] = 1;                                  //最优子结构
                                              
    for (int i = 3; i <= n; i++) {              //dp[i]为到i时的最大积
      for (int j = 1; j < i / 2 + 1; j++) {
        dp[i] = max(dp[i], max(j * (i - j), j * (dp[i - j])));
      }                                         //分为j和i-j的乘积和j和dp[i-j]的成绩，即i-j再分
    }

    return dp[n];
  }
};

int main () {

  return 0;
}