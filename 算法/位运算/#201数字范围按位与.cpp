#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
      int pos = 0;
      while (left != right) {
        left >>= 1;               //当一个数+1时，总会有这么一个规律“某一位后的数字，全部被置为相反数
        right >>= 1;              //不停右移，得到right和left的高位相同时终止
        pos++;                    //一旦某一位改变过(0->1或1->0)，这一位改变后和改变前相与结果肯定是0 那么一连串与下来更为0。之前的位与结果不变
      }
      return left << pos;
    }
};

int main () {

  return 0;
}