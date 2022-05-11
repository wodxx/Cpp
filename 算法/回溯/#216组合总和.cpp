#include <bits/stdc++.h>
using namespaces std;

class Solution {
private:
vector<vector<int>> results;
vector<int> temp;

public:
  vector<vector<int>> combinationSum3(int k, int n) {
    dfs (results, temp, k, n, 1);
    return results;
  }

  void dfs (vector<vector<int>>& results, vector<int>& temp, int k, int n, int start) {
    if (temp.size() == k && n == 0) {
      results.push_back(temp);
      return;
    }

    for (int i = start; i <= 9; i++) {
      if (i <= n) {
        temp.push_back(i);
        dfs (results, temp, k, n - i, i + 1);    //这里直接传入n-i
        temp.pop_back();
      }
    }
  }
};

int main () {

  return 0;
}