#include <iostream>
#include <cmath>
#include <limits.h>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int len = int(nums.size());
    vector<int> dp(len);

    int max_sum = INT_MIN;                          //有负数，注意这里最小值的极限
    dp[0] = nums[0];
    max_sum = nums[0];                              //结果要赋初值

    for (int i = 1; i < len; i++) {
      dp[i] = max(dp[i - 1] + nums[i], nums[i]);   //如果加上nums[i]变小了，则只取nums[i]
      max_sum = max(max_sum, dp[i]);
    }

    return max_sum;
  }
};
int main(){

  return 0;
}