#include <bits/stdc++.h>
using namespace std;

//hash
class Solution {
public:
  vector<int> missingTwo(vector<int>& nums) {
    vector<int> results;
    unordered_map<int, int> m;
    for (auto i : nums) {
      m[i]++;
    }
    for (int i = 1; i <= (nums.size() + 2); i++) {
      if (m[i] == 0) results.push_back(i);
    }
    return results;
  }
};

//抽屉算法
class Solution {
public:
  vector<int> missingTwo(vector<int>& nums) {
    int i = 0;
    nums.push_back(-1);
    nums.push_back(-1);
    while (i < nums.size()) {
      if (i + 1 != nums[i] && nums[i] != -1) { 
    //这里因为数组里有-1，所以不能是nums[nums[i] - 1] != nums[i]，而是nums[i] ！= i+1
        swap (nums[nums[i] - 1], nums[i]);
      } else {
        i++;
      }
    }
    vector<int> results;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == -1) {
        results.push_back(i + 1);
      }
    }
    return results;
  }
};

int main () {

  return 0;
}