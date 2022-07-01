#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0, right = 0, sum = 0;
    int minx = 0;
    while (right < nums.size()) {
      sum += nums[right];
      while (sum >= target) {
        if (right - left + 1 < minx || minx == 0) {
          minx = right - left + 1;           //可能存在加和永远不等于target的情况， 所以minx有为0的情况 
        }
        sum -= nums[left];                   //left只左移一次 和减去一次的值
        left++;
      }
      right++;
    }
    return minx;
  }
};

int main () {

  return 0;
}