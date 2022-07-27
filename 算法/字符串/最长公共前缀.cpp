// 描述
// 给你一个大小为 n 的字符串数组 strs ，其中包含n个字符串 , 编写一个函数来查找字符串数组中的最长公共前缀，返回这个公共前缀。

// 输入：
// ["abca","abc","abca","abc","abcc"]

// 返回值：
// "abc"

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param strs string字符串vector 
     * @return string字符串
     */
  string longestCommonPrefix(vector<string>& strs) {
    // 字符串取片段 substr();
    if (strs.size() == 0) return "";                     
    sort(strs.begin(), strs.end());                     // 排序后只在首尾两字符串里比较(字符串排序按ASCII码大小)
    int length = min(strs[0].size(), strs[strs.size() - 1].size());
    for (int i = 0; i < length; i++) {                 // 确定最短字符串
      if (strs[0][i] != strs[strs.size() - 1][i]) return strs[0].substr(0, i);
    }                                                  // 不相等时返回前面相等的部分 
    return strs[0].substr(0, length);
  }
};

int main () {

  return 0;
}