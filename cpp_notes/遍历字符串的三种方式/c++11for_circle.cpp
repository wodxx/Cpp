/*
 * @Author: your name
 * @Date: 2021-10-19 21:54:33
 * @LastEditTime: 2021-10-20 09:17:01
 * @FilePath: /Cpp/cpp语法/遍历字符串的三种方式/c++11for_circle.cpp
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int value = 0;
int string_to_int(string s2){
  //ch的意思是从string里面取字符，直到取完为止
  for(auto ch : s2){
    value *= 10;
    value += (ch - '0');
  }
  return value;
}

int main(){
  cout<<string_to_int("1234")<<endl;
  return 0;
}

//c++11里面的for循环的底层是用迭代其实现的