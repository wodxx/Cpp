#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    int len = coins.size();
    if (len == 0) return -1;
    vector<int> dp(amount + 1, amount + 1);  // 要求最小值，所以初值设为最大amount + 1

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


// 解法二： 先循环背包，即目标值
class Solution {
public:
  int minMoney(vector<int>& arr, int aim) {
    if (aim == 0) return 0;
    if (arr.size() == 0) return - 1;
    vector<int> dp(aim + 1, 1e9);
    dp[0] = 0;                              // ap[i]:组成i最少需要的货币数
    for (int j = 1; j <= aim; j++) {
      for (auto c : arr) {
      //从dp[0]开始，在之前的状态上叠加
      //计算dp[6],6-arr[0]=1，而dp[1]==1e9,跳过
      //6-arr[1]=4,而dp[4]==2(拼出4块钱最少需要两张2块)，==》dp[6]=dp[4]+1=3
      //6-arr[2]=3,而dp[3]==1(拼出3块钱最少需要一张3块)，==》dp[6]=min(3,dp[3]+1)=2
        if (j >= c && dp[j - c] != 1e9) 
          dp[j] = min(dp[j], dp[j - c] + 1);
      // 因为要试每张货币的可能性，所以要比较dp[i]
      }
    }
    return dp[aim] == 1e9 ? -1 : dp[aim];
  }
};

int main () {

  return 0;
}