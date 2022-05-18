#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
vector<string> results;
string str;
public:
  void backTrack(int n, int left, int right) {
    if ((left + right) == 2 * n) {   //终止条件为左右括号之和为2倍n,或者写成是str的长度为2*n
      results.push_back(str);
      return;
    }
    if (left < n) {
      str.push_back('(');
      backTrack(n, left + 1, right);
      str.pop_back();
    }
    if (right < left) {
      str.push_back(')');
      backTrack(n, left, right + 1);
      str.pop_back();
    }
  }
  vector<string> generateParenthesis(int n) {
    backTrack (n, 0, 0);   //左右括号的个数从0开始做加法
    return results;
  }
};

// //传入str写法
// class Solution {
// private:
// vector<string> results;
// string str;
// public:
//   void backTrack (int right, int left, string str) { //用不到n，所以不设n的形参
//     if (left == 0 && right == 0) {
//       results.push_back(str);
//       return;
//     }
//     if (left > 0) {
//       backTrack (right, left - 1, str + '(');  //left不用尽(从n到0)就可以一直递归，每次左边加一个'('
//     }    
//     if (right > left) {
//       backTrack (right - 1, left, str + ')');  //右边加')'
//     }
//   }
//   vector<string> generateParenthesis(int n) {
//     backTrack (n, n, str);   
//     return results;
//   }
// };

int main () {

  return 0;
}