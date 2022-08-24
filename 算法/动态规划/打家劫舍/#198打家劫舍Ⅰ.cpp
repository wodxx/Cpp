#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    vector<int> dp(nums.size() + 1);   
    dp[0] = nums[0];            //初值为0
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < nums.size(); i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);  
    }                    //i为本值，要加上本值得话为索引值i-1

    return dp[nums.size() - 1];
  }
};

int main () {

  return 0;
}