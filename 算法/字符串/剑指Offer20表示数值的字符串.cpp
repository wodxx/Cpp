#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool scanint(const string s, int & index) {
    if (s[index] == '+' || s[index] == '-')  ++index; //检测整数的符号 
    return scanunsignedint(s, index);
  }
  bool scanunsignedint(const string s, int & index) {
    int curnum = index;
    while (index != s.size() && s[index] >= '0' && 
    s[index] <= '9') index++;                        //整数部分每一个字符在0-9之间
    return index > curnum;
  }
  bool isNumber(string s) {
    if (s.size() == 0) return false;
    int index = 0;
    while (s[index] == ' ') index++;
    bool num = scanint(s, index);
    if (s[index] == '.') {
      ++index;
      num = scanunsignedint(s, index) || num;        //有小数点后继续检测无符号整数部分
    }                                                //这里不能写成num||scanunsingendint
    if (s[index] == 'E' || s[index] == 'e') {
      ++index;
      num = num && scanint(s, index);                //有e或E后继续整数检测
    }       
    while (s[index] == ' ') ++index;                 //检测后面是否有空格
    return num && index == s.size();
  }
};

int main () {

  return 0;
}

// 参考题解 https://leetcode.cn/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof
// /solution/mian-shi-ti-20-biao-shi-shu-zhi-de-zi-fu-chuan-y-2/
// 作者：Krahets（leetcode）