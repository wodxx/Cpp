#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    int len = coins.size();
    if (len == 0) return -1;
    vector<int> dp(amount + 1, amount + 1);

    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
      for (auto j : coins) {             //每一枚硬币来凑i从1到amount
        if (j > i) continue;
        dp[i] = min(dp[i], dp[i - j] + 1); //凑i的面值，遇到j时，比j大，只用一次j的硬币数为dp[i - j] + 1
      }
    }

    if (dp[amount] == amount + 1) return -1;
    return dp[amount];
  }
};

int main () {

  return 0;
}