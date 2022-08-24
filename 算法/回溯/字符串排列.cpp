#include <bits/stdc++.h>
using namespace std;

// 此题去重原理同全排列Ⅱ 原字符串(数字)先要排序
class Solution {
private:
  vector<string> result;
  string temp;
public:
  void backTrack(string str, vector<bool>& used) {
    // 判断 临时字符串的大小是否为n
    if (temp.size() == str.size()) {
      result.push_back(temp);
      return;
    }
    for (int i = 0; i < str.size(); i++) {
      if (used[i] == false) {
        // i-1项和i项相等且i-1项的值未使用过 则continue
        if (i != 0 && str[i - 1] == str[i] && used[i - 1] == false) continue;
          used[i] = true;
          temp += str[i];
          backTrack(str, used);
          temp.pop_back();
          used[i] = false;
      } 
    }
  }
  vector<string> Permutation(string str) {
    int n = str.size();
    if (n == 0) return result;
    sort(str.begin(), str.end());
    vector<bool> used(n, false);
    backTrack(str, used);
    return result;
  }
};

int main () {

  return 0;
}
