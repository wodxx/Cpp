#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool judgezhishu(unsigned int n) {                  //判断质数
    if (n < 2) return false;
    if (n == 2) return true;
    for (int i = 2; i <= sqrt(n); i++) {
      if (n % i == 0) return false;
    }
    return true;
  }

  int countPrimeSetBits(int left, int right) {
    int result = 0;
    for (int i = left; i <= right; i++) {
      int count = 0, num = i;
      while (num) {                                  //进入内循环变量名称要替换
        num &= (num - 1);                            //求二进制中1的个数
        count++;
      }
      if (judgezhishu(count)) result++;
    }

    return result;
  }
};

int main () {

  return 0;
}