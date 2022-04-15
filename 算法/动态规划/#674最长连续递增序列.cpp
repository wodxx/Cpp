#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findLengthOfLCIS(vector<int>& nums) {
    if(nums.empty()) return 0;
    int len = nums.size();
    vector<int> dp(len + 1, 1);              //dp[i]到i的最长连续递增序列个数

    int result = 1;
    for (int i = 0; i < len - 1; i++) {
      if (nums[i + 1] > nums[i]) {
        dp[i + 1] = dp[i] + 1;
      }
      result = max(result, dp[i + 1]);
    }
    return result;
  }
};

int main(){

  return 0;
}