#include <bits/stdc++.h>
using namespace std;

// 解1 双指针， 从后遍历s 截取一个单词加给result
class Solution {
public:
  string reverseWords(string s) {
    string result;
    if (s.size() == 0) return result;
    int i = s.size() - 1;
    while (i >= 0) {
      int wordsize = 0;
      while (i >= 0 && s[i] == ' ') --i;                        // 遍历过后面的空格
      while (i >= 0 && s[i] != ' ') {
        i--;
        wordsize++;
      }
      if (wordsize) result += s.substr(i + 1, wordsize) + ' ';  // i此时已经指向空格，故从i+1开始截取
    }
    return result.substr(0, result.size() - 1);
  }
};

// 解2 辅助栈
class Solution {
public:
  string reverseWords(string s) {
    string result;
    string word;
    stack<string> vec;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != ' ') {
        word += s[i];
        if (i == s.size() - 1 || s[i + 1] == ' ') {   // word 入栈时机：下一个字符为空字符
          vec.push(word);   
          word = "";
        }
      }
    }
    while (!vec.empty()) {
      result += vec.top();
      vec.pop();
      if (!vec.empty()) result += ' ';
    }
    return result;
  }
};

int main () {

  return 0;
}