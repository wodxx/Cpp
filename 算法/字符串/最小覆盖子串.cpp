// 描述

// 给出两个字符串 s 和 t，要求在 s 中找出最短的包含 t 中所有字符的连续子串。

// 数据范围：0 \le |S|,|T| \le100000≤∣S∣,∣T∣≤10000，保证s和t字符串中仅包含大小写英文字母
// 要求: 时间复杂度 O(n)O(n)
// 例如：
// S ="XDOYEZODEYXNZ"S="XDOYEZODEYXNZ"
// T ="XYZ"T="XYZ"
// 找出的最短子串为"YXNZ""YXNZ".

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param S string字符串 
     * @param T string字符串 
     * @return string字符串
     */
  string minWindow(string S, string T) {
        // write code here
    string result;
    if (S.size() == 0 || T.size() == 0) return result;
    map<char, int> m;
    for (auto i : T) m[i]++;
    int left = 0;                     // 左指针
    int count = 0;                    // 记录在窗口内的字符个数
    int minlen = INT_MAX;             // 初始化一个最短窗口字符长度
    for (int right = 0; right < S.size(); right++) {
      if (m.find(S[right]) != m.end()) {
        if (m[S[right]] > 0) count++;  // 窗口内的值有T中的字符 技术加1
        m[S[right]]--;                 // 去掉已经记过的
        while (count == T.size()) {
          if (m.find(S[left]) != m.end()) {
            if (minlen > right - left + 1) {
              minlen = right - left + 1;         // 更新窗口内最短字符的长度
              result = S.substr(left, right - left + 1);  // 结果截取
            }
            m[S[left]]++;                         //舍弃窗口左边字符串，继续移动窗口
            if (m[S[left]] > 0) count--;          // 如果左边继续相同，则count不递减 比如 AABC 此时窗口在
          }                                       // 第一个A到C
          left++;                               
        }                                        
      }
    }
    return result;
  }
};

int main () {

  return 0;
}