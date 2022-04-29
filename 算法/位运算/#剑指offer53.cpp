#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int ans = 0;
    int ans1 = 0;

    for (int i = 0; i <= nums[nums.size() - 1]; i++) {
      ans ^= i;
    }

    for (int j = 0; j < nums.size(); j++) {
      ans1 ^= nums[j];
    }
    if (ans != ans1) return ans ^ ans1;        //ans = ans1 ^ 要求的数字
    if (nums[0] != 0) return 0;                //0被缺失
    else return nums[nums.size() - 1] + 1;     //没有缺失
  }
};

int main () {

  return 0;
}