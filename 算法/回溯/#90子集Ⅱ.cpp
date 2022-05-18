#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
vector<vector<int>> results;
vector<int> temp;
public:
  void backTrack (vector<int>& nums, int start){
    if (start > nums.size()) return;
    results.push_back(temp);
    for (int i = start; i < nums.size(); i++) {
      if (i != start && nums[i] == nums[i - 1]) continue;        //去重
      temp.push_back(nums[i]);
      backTrack(nums, i + 1);
      temp.pop_back();
    }
  }
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    backTrack(nums, 0);
    return results;
  }
};

int main () {

  return 0;
}