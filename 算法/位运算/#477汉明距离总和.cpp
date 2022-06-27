#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int totalHammingDistance(vector<int>& nums) {
    int results = 0;
    int len = nums.size();        //元素长度
    for (int i = 0; i <= 30; i++) {
      int n = 0;                  //所有数某一位上出现的1的总数
      for (auto c : nums) {
        n += (c >> i) & 1;
      }
      results += (len - n) * n;  //次数 （len - n) * n
    }
    return results;
  }
};

int main () {

  return 0;
}

// 先处理最简单的场景，对于[4, 14, 2]，
// 元素个数为3，4表示为0100，14表示为1110，2表示为0010，先考虑第1位数不同的总次数，
// 个位一共出现0个1，那么该位不同的总次数就是(3 - 0) * 0 = 0，对于第2位， 出现2个1，那么次数就是(3 - 2) * 2 = 2。

// 所以可以知道，要求某一位不同的总次数，该位出现1的次数为n，元素总数为m，答案就是(m - n) * n，
// 接下来要做的就是统计每一位上出现1的次数，这个就直接位运算解决了。