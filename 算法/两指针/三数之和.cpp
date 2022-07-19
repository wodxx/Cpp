// 数组中求三数之和为0 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &num) {
    sort(num.begin(), num.end());
    vector<vector<int> > result;
    int len = num.size();
    for (int i = 0; i < len - 2; i++) {
      if (num[0] > 0) break;
      if (i > 0 && num[i] == num[i - 1]) continue;
      int left = i + 1;
      int right = len - 1;
      while (left < right) {
        vector<int> temp;
        if ((num[left] + num[right] + num[i]) > 0) right--;
        else if ((num[i] + num[left] + num[right]) < 0) left++;
        else { // 满足条件 三个数组进数组
          temp.push_back(num[i]);
          temp.push_back(num[left]);
          temp.push_back(num[right]);
          result.push_back(temp);
          left++;
          right--;
          // 去除重复的三组数
          while (left < right && num[left] == num[left - 1]) left++;
          while (left < right && num[right] == num[right + 1])right--;
        }
      }
    }
    return result;
  }
};

int main () {

  return 0;
}