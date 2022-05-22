#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numJewelsInStones(string jewels, string stones) {
    int results = 0;
    map<char, bool> m;
    for (auto i : jewels) m[i] = true;
    for (auto x : stones) {
      if (m[x]) results++;
    }
    return results;
  }
};

int main () {

  return 0;
}