#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
      int count = 0;
      while(n){
        ++count;
        n = (n - 1) & n;  //整数n和n - 1 作位与运算，把最右边的1变成0
      }
      return count;      //变后继续减一作与运算，运算次数就是二进制1的个数
    }
};

int main(){
  return 0;
}