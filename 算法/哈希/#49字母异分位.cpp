#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> results;
    map<string, vector<string>> m;
    for (auto i : strs) {
      //遍历每一个字符串
      string temp = i;          
     //每一个字符串排序操作前赋值给temp
      sort(temp.begin(), temp.end());
     //对每一个字符串排序作为m里的键
     m[temp].push_back(i);
     //temp即排序后相同的作为m里temp的值push到vector
    }
    for (auto it = m.begin(); it != m.end(); ++it) {
      results.push_back(it -> second);
      //遍历m，把每个键的值(数组)push到results
    }
    return results;
  }
};

int main () {

  return 0;
}