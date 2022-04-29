#include <bits/stdc++.h>                            //不用 + — 符号做加法
using namespace std;

class Solution {
public:
  int getSum(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;

    int FucK_sum = 0, 艹 = 0;
    while (b != 0) {
      FucK_sum = a ^ b;                              //先做异或运算，即只加不进位
      艹 = (unsigned int)(a & b) << 1;               //再做与运算+左移运算，即进位操作
      a = FucK_sum;
      b = 艹;
    }

    return FucK_sum;
  }
};

int main () {

  return 0;
}