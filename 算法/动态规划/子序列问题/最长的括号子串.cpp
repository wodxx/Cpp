// 描述
// 给出一个长度为 n 的，仅包含字符 '(' 和 ')' 的字符串，计算最长的格式正确的括号子串的长度。
// 例1: 对于字符串 "(()" 来说，最长的格式正确的子串是 "()" ，长度为 2 .
// 例2：对于字符串 ")()())" , 来说, 最长的格式正确的子串是 "()()" ，长度为 4 .
// 字符串长度：0 \le n \le 1\times10^50≤n≤1×10 
// 5
// 要求时间复杂度 O(n)O(n) ,空间复杂度 O(n)O(n).
// 输入："(()"
// 返回值：2

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    if (s.size() <= 1) return 0;
    int result = 0;
    vector<int> dp(s.size());                // dp[i] 前i个括号前格式正确的括号字串长度
    dp[0] = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ')' && s[i - dp[i - 1] - 1] == '(')
        dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] +2;
      result = max(result, dp[i]);
    }
    return result;
  }
};

// 这题主要理解那一行核心代码dp[i]=dp[i-1]+2+dp[i-dp[i-1]-2];即可，其中dp[i-1]是指内部原来的长度dp[i-dp[i-1]-2]是指是否要连接上之前的长度，
// 2是指符合条件的情况下要加上的长度，更新表达式当且仅当左右括号分别匹配

int main () {

  return 0;
}