#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int integerReplacement(int n) {
    if (n == 1) return 0;
    uint64_t num = n;                             //操作之后可能超出int，故这里用long long型
    int result = 0;

    while (num != 1) {
      if ((num & 1) == 1) {                       //为奇数
        if ((num != 3) && (num & 3) == 3) {       //该数不是3且其二进制最低位有2个1以上时，先加一
          num++;
          result++;
        } else {                                 //该数低位没有2个以上的1时，先减一
          num--;
          result++;
        }
      }
      num >>= 1;                                 //为偶数
      result++;
    }
    return result;
  }
};

int main () {

  return 0;
}