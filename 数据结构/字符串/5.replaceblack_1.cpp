/*
 * @Author: your name
 * @Date: 2021-10-21 11:04:10
 * @LastEditTime: 2021-10-21 11:10:36
 * @FilePath: /Cpp/数据结构/字符串/5.replaceblack_1.cpp
   剑指offer NO.5:替换法！
 */

#include <iostream>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string s2;
        for(size_t i = 0; i < s.size(); i++){
            if (s[i] == ' ') {
                s2 += "%20";
            } else {            //这里为了循环清楚，要写else
                s2 += s[i];
            }
        }
        return s2;
    }
};

int main(){
  return 0;
}
