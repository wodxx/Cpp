#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> m;
    for (auto i : nums) {
      m[i]++;
    }
    for (auto it = m.begin(); it != m.end(); ++it) {
      if (it -> second >= 2) {
        return true;
        break;
      }
    }
    return false;
  }
};

int main () {

  return 0;
}