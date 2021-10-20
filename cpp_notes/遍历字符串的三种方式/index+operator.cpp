/*
 * @Author: your name
 * @Date: 2021-10-19 21:18:22
 * @FilePath: /Cpp/cpp语法/遍历字符串的三种方式/index+operator.cpp
 
  题目：把字符串“1234”转换为整形1234
 */

#include <iostream>
#include <string>
using namespace std;

int value = 0;
int string_to_int(string s1){
  for(size_t i = 0; i < s1.size(); i++){
    value *= 10;
    value += s1[i] - '0';
  }
  return value;
}

int main(){
  cout<<string_to_int("1234")<<endl;
  return 0;
}

/*
size_t : 无符号整形，也就是unsigned long（64位机）和 unsigned int（32位机）;
ssize_t : 有符号整形，在32位机器上等同于int，在64位机器上等同于long int;
*/