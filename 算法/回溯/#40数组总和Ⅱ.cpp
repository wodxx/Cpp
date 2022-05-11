#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
vector<vector<int>> results;
vector<int> temp;
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    int len = candidates.size();
    sort(candidates.begin(), candidates.end());        //先排序 后面去重
    dfs (candidates, target, 0, len, 0);
    return results;
  }

  void dfs (vector<int>& candidates, int target, int start, int len, int sum) {
    if (sum == target) {
      results.push_back(temp);
      return;
    }

    for (int i = start; i < len && sum + candidates[i] <= target; i++) {
      if (i > start && candidates[i] == candidates[i - 1]) continue;      //去重
        temp.push_back(candidates[i]);                            //i大于start且此时i的值与i-1的值相等时，跳出
        dfs (candidates, target, i + 1, len, sum + candidates[i]); //不能重复使用，则start从i+1开始。
        temp.pop_back();
    }
  }
};

int main () {

  return 0;
}