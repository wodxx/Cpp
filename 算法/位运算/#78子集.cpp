#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    int N = nums.size();         //这里N的上限为10，可以用位移运算
    int S = 1 << N;              //计算nums数组的子集个数，为2^(nums.size()),左移一次乘2

    vector<vector<int>> results;
    for (int i = 0; i < S; i++) {
      vector<int> temp;
      for (int j = 0; j < N; j++) {
        if (i & (1 << j)) temp.push_back(nums[j]);  //根据1左移后的位数&i结果来判断nums中此时j位的数选不选
      }
      results.push_back(temp);
    }

    return results;
  }
};

int main () {

  return 0;
}