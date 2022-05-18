#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
vector<vector<int>> results;
vector<int> temp;
public:
  void backTrack (vector<int>& used, vector<int>& nums) {
    if (temp.size() == nums.size()) {
      results.push_back(temp);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (used[i] == 0) {
        if (i > 0 && nums[i - 1] == nums[i] && used[i - 1] == 0) continue; //i项未使用过，i项和i-1项值相等且i-1项未使用过(即未回溯过)时continue
        //if (i > 0 && nums[i - 1] == nums[i] && used[i - 1] != 0) continue; 这里最后改为i-1项的值已使用过（已回溯过）也可以通过，复杂度高于上面
        temp.push_back(nums[i]);
        used[i] = 1;
        backTrack (used, nums);
        temp.pop_back();
        used[i] = 0;
      }
    }
  }
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> used(nums.size(), 0);
    backTrack (used, nums);
    return results;
  }
};

int main () {
  
  return 0;
}

//【理解】
// 以[1,1,2]为例，在递归到第1个元素（从0开始编号）时，与第0个元素数值相同，如果第0个元素是用过（即在目前的序列中），
// 那么会产生 [1,1]这种序列；如果第0个元素是没有用过（不在目前的序列中），
// 而第0个元素的元素值和第1个元素的元素值是相同的，第1个元素能够表达的情况在第0个元素在序列中时，都已经涵盖到了，
// 所以为了去重就不需要再把第一个元素进一步递归了。