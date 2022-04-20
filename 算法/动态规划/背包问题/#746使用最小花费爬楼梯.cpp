#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    int len = cost.size();
    vector<int> dp(len);                            //定义数组带上长度

    dp[0] = cost[0];
    dp[1] = cost[1];                                //可以从第0个或者第1个台阶开始，因此跨过此台阶的最小花费均为本身花费

    for(int i = 2; i < len; i++){                   //某一台阶的花费取前一阶和前两阶花费中的最小值
      dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];  //dp[i]应该理解为迈过第i个台阶所需的最小花费
    }

    return min(dp[len - 1], dp[len - 2]);           //最后一步可以理解为不用花费，所以取倒数第一步，第二步的最少值
  }                                                 //因为最后一步的花费没有用，不用再往上走了
};

int main(){

  return 0;
}