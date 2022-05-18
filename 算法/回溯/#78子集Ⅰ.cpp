#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
vector<vector<int>> results;
vector<int> temp;
public:
  void backTrack (vector<vector<int>>& results, vector<int>& temp, vector<int>& nums, int start) {
    if (start > nums.size()) return;
    results.push_back(temp);
    for (int i = start; i < nums.size(); ++i) {
      temp.push_back(nums[i]);
      backTrack(results, temp, nums, i + 1);       //这里是i+1
      temp.pop_back();
    }
  }
  vector<vector<int>> subsets(vector<int>& nums) {
    backTrack (results, temp, nums, 0);
    return results;
  }
};

int main () {

  return 0;
}