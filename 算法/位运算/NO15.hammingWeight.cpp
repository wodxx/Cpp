/*编写一个函数，输入是一个无符号整数（以二进制串的形式），
返回其二进制表达式中数字位数为 '1' 的个数（也被称为 汉明重量).）。*/

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(unsigned int n) {
      int count = 0;
      while(n){
        if (n & 1) count++; //一个整数与1作与运算结果为1,则说明该整数的二进制最右为1
        n = n >> 1;         //然后该整数右移1
      }
      return count;
    }
};

int main(){
  return 0;
}