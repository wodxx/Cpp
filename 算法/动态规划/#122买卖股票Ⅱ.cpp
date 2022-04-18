// [题目]
//   给定一个数组 prices ，其中 prices[i] 表示股票第 i 天的价格。
//   在每一天，你可能会决定购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以购买它，然后在 同一天 出售。
//   返回 你能获得的 最大 利润 。

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();

    vector<vector<int>> dp(len + 1, vector<int>(2, 0));
    dp[0][0] -= prices[0];     //dp[i][0]表示第i天持股时所得现金(分为昨天有股和当天买入)
    dp[0][1] = 0;              //dp[i][1]表示第i天无股时所得现金(分为当天昨天无股和当天卖出)

    for (int i = 1; i < len; i++) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }

    return dp[len - 1][1];
  }
};

int main () {

  return 0;
}