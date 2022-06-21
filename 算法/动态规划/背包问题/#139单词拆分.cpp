#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size(), false);
    unordered_set<string> wordset(wordDict.begin(), wordDict.end());

    //dp[i]表示s中前i各字符能否拆分成字典里的值，依次遍历完s后返回
    dp[0] = true;
    for (int i = 1; i <= s.size(); i++) {
      for (int j = 0; j < i; j++) {
        string word = s.substr(j, i - j);
        if (wordset.find(word) != wordset.end() & dp[j]) {      //j前后区间都能在字典里找到则返回true
          dp[i] = true;     
        }
      }
    }

    return dp[s.size()];
  }
};

int main () {

  return 0;
}