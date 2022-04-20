#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    int len = nums.size();
    vector<int> dp(len, 1);                 //只有一个元素时长度为1
    if(nums.empty()) return 0;             //dp[i]的初始化：每一个i，对应的dp[i]（即最长上升子序列）起始大小至少都是1.

    int max_len = 0;

    for(int i = 0; i < len; i++) {        //dp[i]表示为到nums[i]截至时的子序列长度
      for(int j = 0; j < i; j++) {
        if(nums[i] > nums[j]) {
          dp[i] = max(dp[i], dp[j] + 1);  //严格子序列，当dp[i]大于他的前一个数时，计算长度要加上1（即nums[i]本身）。
        }                                 //当i=1时，dp[1]=max(dp[1],dp[0] + 1),dp[1]==1,dp[j]==1.
      }
      max_len = max(max_len, dp[i]);      //比较到每个nums[i]子序列的最大值
    }
    return max_len;
  }
};

int main(){

  return 0;
}