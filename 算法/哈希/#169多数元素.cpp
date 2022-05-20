#include <bits/stdc++.h>
using namespace std;

//hash
class Solution {
public:
  int majorityElement(vector<int>& nums) {
    unordered_map<int, int> m;
    for (auto i : nums) {
      if (m[i]++ >= nums.size() / 2) {
        return i;
      }
    }
    return 0;
  }
};

//抵消法
class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int count = 0, results = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (count == 0) {
        results = nums[i];
        count = 1;
      } else {
        results == nums[i] ? count++ : count--;
      }
    }
    return results;
  }
};

int main () {

  return 0;
}