#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);                 //求最小，初值赋最大
    dp[0] = 0;
    //背包问题，n为总体积，从1到n的完全平方数为物品
    //dp[i]为组成i的完全平方数的最少值
    //这里的dp[i - j * j] + 1是指：dp[i - j * j]最少有几个平方数构成，再加上j*j这一种构成方式（加1的由来）
    for (int i = 0; i <= n; i++) {
      for (int j = 1; j * j <= i; j++) {             //这里要等于i
        dp[i] = min(dp[i], dp[i - j * j] + 1);
      }
    }
    return dp[n];
  }
};

int main () {

  return 0;
}