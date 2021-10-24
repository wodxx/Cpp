/*
 * @Author: your name
 * @Date: 2021-10-21 08:45:03
 * @LastEditTime: 2021-10-21 11:10:37
 * @FilePath: /Cpp/数据结构/字符串/replaceblack.cpp
   剑指offer NO.5:双指针法！
 */

#include <iostream>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
      int space = 0;//空格数量
      int len = s.size();
      for(int i = 0; i < len; i++){
        if (s[i] == ' ') space++;
      }
      s.resize(len + 2 * space);
      //resize()重新定义长度函数
      int i = len;
      int j = s.size();
      //这里已经重新计算了长度，故这里的s.size（）已经是新长度
      while(i >= 0 && j > i){  //循环截至的条件是两指针相等，i可以等于0
        if(s[i] == ' '){
          s[j--] = '0';  //字符串元素用单引号
          s[j--] = '2';
          s[j--] = '%';
        } else {
          s[j--] = s[i];
        }
        i--;
      }
    return s;
    }
};

int main(){
  return 0;
}