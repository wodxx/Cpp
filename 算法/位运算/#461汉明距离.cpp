#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int hammingDistance(int x, int y) {
    int count = 0;
    while ((x != 0) || (y != 0)) {           //当两个数都为0时终止
      if ((x & 1) != (y & 1)) count++;       //与1获取最低位，两个的最低位不同则count++
      x >>= 1, y >>= 1;                      //右移一位比较次低位
    }
    return count;
  }
}

int main () {

  return 0;
}