// 描述
// 假设你有一个数组prices，长度为n，其中prices[i]是某只股票在第i天的价格，请根据这个价格数组，返回买卖股票能获得的最大收益
// 1. 你最多可以对该股票有两笔交易操作，一笔交易代表着一次买入与一次卖出，但是再次购买前必须卖出之前的股票
// 2. 如果不能获取收益，请返回0
// 3. 假设买入卖出均无手续费

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() == 0) return 0;
    vector<vector<int>> dp(prices.size() + 1, vector<int> (5, 0));
    dp[0][1] = -prices[0];
    dp[0][3] = -prices[0];
    for (int i = 1; i < prices.size(); i++) {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);     // 第一次第i天持股的状态
      dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);     // 第一次第i天卖出的转态
      dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);     // 第二次第i天持股的状态
      dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);     // 第二次第i天卖出的状态
    }
    return dp[prices.size() - 1][4];
  }
};

int main () {
  
  return 0;
}