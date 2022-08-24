/*******************************************************************
[题目]
  给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
  你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。
  设计一个算法来计算你所能获取的最大利润。
  返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
********************************************************************/

#include <bits/stdc++.h>
using namespace std;

// 动态规划解法
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() == 0) return 0;
    vector<vector<int>> dp(prices.size(), vector<int> (2));
    dp[0][0] -= prices[0];                               // dp[i][0]: 第i填持股能获得的收益 
    dp[0][1] = 0;                                        // dp[i][1]: 第i天不持股能获得的收益
    for (int i = 1; i < prices.size(); i++) {
      dp[i][0] = max(dp[i - 1][0], -prices[i]);          // 前一天持股和恰好是当天买入股二选最大
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]); // 前一天不持股和当天卖出的的情况二选最大
    }                                                    // 当天卖出的情况为前一天持股的收益加当天的股价之和
    return dp[prices.size() - 1][1];
  }
};


// 最优间距解法
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int maxx = 0;
    //int len = prices.size();
    int minx = int(1e9);           //定义为最小值

    for(int i : prices){
      maxx = max(maxx, i - minx);
      minx = min(minx, i);
    }

    return maxx;
  }

  // for(int i = 0; i < len - 1; i++){
  //   for(int j = i + 1; j < len; j++){
  //     maxx = max(maxx, prices[j] - prices[i]);
  //   }
  // }

  // return maxx;
  
};

int main () {

  return 0;
}

