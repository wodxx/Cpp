/*******************************************************************
[题目]
  给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
  你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。
  设计一个算法来计算你所能获取的最大利润。
  返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
********************************************************************/

#include <bits/stdc++.h>
using namespace std;

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

