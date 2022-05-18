#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
vector<vector<int>> results;
vector<int> temp;
public:
  void backTrack (vector<bool>& used, vector<int>& nums) {
    if (temp.size() == nums.size()) {
      results.push_back(temp);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (used[i] == true) continue;                       //判断该数字是否使用过,推进used数组的其实是下标
      used[i] = true;                                      
      temp.push_back(nums[i]);
      backTrack(used, nums);                              //开始跳栈后，连续执行下面两条语句，直到跳栈完全
      temp.pop_back();
      used[i] = false;
    }
  }
  vector<vector<int>> permute(vector<int>& nums) {
    vector<bool> used(nums.size(), false);
    backTrack (used, nums);
    return results;
  }
};

int main () {

  return 0;
}