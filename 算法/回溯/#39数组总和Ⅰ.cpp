#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<vector<int>> results;
  vector<int> temp;
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    dfs (candidates, target, 0);
    return results;
  }

  void dfs (vector<int>& candidates, int target, int start) {
    if (target == 0) {                                 //递归终止条件
      results.push_back(temp);
      return;
    }
    for (int i = start; i < candidates.size(); i++) {
      if (candidates[i] <= target) {                   //不满足该条件则i++
        temp.push_back(candidates[i]);
        dfs (candidates, target - candidates[i], i);   //元素可重复选取，继续从i开始
        temp.pop_back();                               //清除上一组数据
      }     
    }
  }
};

int main () {

  return 0;
}