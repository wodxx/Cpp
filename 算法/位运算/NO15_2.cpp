#include <iostream>
using namespace std;

class Solution {
public:
    //如果给的整数不是无符号的
    int hammingWeight(int n) {
      int flag = 1;
      int count = 0;
      while(flag){
        if(n & flag) count++;    //这个整数和1作位运算
        flag = flag << 1;        //将1左移1位，变2,2的二进制表示右数第二位为1，能判断n的次底位是不是1
      }
      return count;
    }
};

int main(){
  return 0;
}