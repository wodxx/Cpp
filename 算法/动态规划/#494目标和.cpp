#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    int len = nums.size();

    for (int i = 0; i < len; i++) {
      sum += nums[i];                   //数组之和
    }

    if (sum < target) return 0;         // 保证(sum - target)/2为非负整数（偶数整数）
    if ((sum - target) < 0 || (sum - target) % 2 != 0) return 0;

    int neg = (sum - target) / 2;
    vector<vector<int>> dp(len + 1, vector<int>(neg + 1));
    dp[0][0] = 1;                       //dp[i][j]表示从i个数里面组成和为neg的不同表达式个数
    for (int i = 1; i <= len; i++) {
      for (int j = 0; j <= neg; j++) {  //neg<nums[j] 不能选j，dp[i][j] = dp[i - 1][j]
        dp[i][j] = dp[i - 1][j];        //neg>=nums[j],能选j，总的个数为dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
        if (j >= nums[i - 1]) {
          dp[i][j] += dp[i - 1][j - nums[i - 1]];
        }
      }
    }

    return dp[len][neg];
  }
};

int main () {

  return 0;
}