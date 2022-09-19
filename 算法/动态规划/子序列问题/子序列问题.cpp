#include <iostream>
#include <vector>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 题型1： 求最长 连续 递增序列的大小[leetcode674题]

class Solution {
public:
  int findLengthOfLCIS(vector<int>& nums) {
    if(nums.empty()) return 0;
    int len = nums.size();
    vector<int> dp(len + 1, 1);                 //dp[i]到i的最长连续递增序列个数

    int result = 1;
    for (int i = 0; i < len - 1; i++) {
      if (nums[i + 1] > nums[i]) {
        dp[i + 1] = dp[i] + 1;                  // 要求连续 区别于300题
      }
      result = max(result, dp[i + 1]);
    }
    return result;
  }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 题型2：求最长递增子序列的大小【leetcode300题】
class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {     // 不要求连续 区别于674题
    int len = nums.size();
    vector<int> dp(len, 1);                //只有一个元素时长度为1
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 题型3： 连续子数组的最大和
class Solution {
  public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int n = array.size();
        int result = INT_MIN;
        if (n == 1) return array[0];
        vector<int>dp(n + 1, array[0]);
        dp[0] = array[0];
        for (int i = 1; i < n; i++) {                          // dp[i]:加上第i个数之后的连续子树组的和
            dp[i] = max(dp[i - 1] + array[i], array[i]);       // 这里最大取到n-1
            result = max(result, dp[i]);
        }
        return result;
    }
};

int main(){

  return 0;
}
