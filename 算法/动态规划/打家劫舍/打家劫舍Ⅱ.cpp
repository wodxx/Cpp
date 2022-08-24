// 描述
// 你是一个经验丰富的小偷，准备偷沿湖的一排房间，每个房间都存有一定的现金，为了防止被发现，你不能偷相邻的两家，即，如果偷了第一家，就不能再偷第二家，如果偷了第二家，那么就不能偷第一家和第三家。沿湖的房间组成一个闭合的圆形，即第一个房间和最后一个房间视为相邻。
// 给定一个长度为n的整数数组nums，数组中的元素表示每个房间存有的现金数额，请你计算在不被发现的前提下最多的偷窃金额。

// 数据范围：数组长度满足 1 \le n \le 2\times10^5 \1≤n≤2×10 
// 5
//   ，数组中每个值满足 1 \le nums[i] \le 5000 \1≤nums[i]≤5000

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int calMax(int start, int end, vector<int>& nums) {
    vector<int> dp(nums.size());                             // 包括下标i之前的能偷到的最大值
    if (start == end) return nums[start];
    dp[start] = nums[start];
    dp[start + 1] = max(nums[start], nums[start + 1]);
    for (int i = start + 2; i <= end; i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[end];
  }
  int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    int case1 = calMax(0, nums.size() - 2, nums);             // 递归，传递两个区间
    int case2 = calMax(1, nums.size() - 1, nums);
    return max(case1, case2);
  }
};

int main () {
  
  return 0;
}