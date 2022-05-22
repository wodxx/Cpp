#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> results; 
    unordered_map<int, int> m;
    priority_queue<pair<int, int>> q; //优先队列
    for (auto i : nums) m[i]++;
    for (auto it = m.begin(); it != m.end(); it++) {
      q.push({it -> second, it -> first});
    }       
    while (k--) {
      results.push_back(q.top().second);       //这里用·不用->
      q.pop();                                 //priority顶元素的second
    }
    return results;
  }
};

int main () {

  return 0;
}