#include<bits/stdc++.h>
using namespace std;
//同“完全背包（硬币问题）”
class Solution {
public:
  int change(int amount, vector<int>& coins) {
    int len = coins.size();
    vector<vector<int>> dp(len + 1, vector<int>(amount + 1, 0));
    
    dp[0][0] = 1;                                //边界条件
    for (int i = 1; i <= len; i++) {
      for (int j = 0; j <= amount; j++) {
        for (int k = 0; k <= j / coins[i - 1]; k++) {
          dp[i][j] += dp[i - 1][j - k * coins[i - 1]];
        }
      }
    }

    return dp[len][amount];
  }
};

int main () {

  return 0;
}