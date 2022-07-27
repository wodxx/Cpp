// 给定一个长度为n的数组arr，返回arr的最长无重复元素子数组的长度，无重复指的是所有数字都不相同。
// 子数组是连续的，比如[1,3,5,7,9]的子数组有[1,3]，[3,5,7]等等，但是[1,3,7]不是子数组

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& arr) {
        // write code here
      int len = arr.size();
      if (len < 2) return len;
      // 用哈希集 判断是否当前值曾出现过
      int fast = 0, slow = 0;
      set<int> se;
      int result = 0;
      while (fast < len) {
        // 快慢指针维持一个 窗口 且该窗口在set里无重复
        if (!se.count(arr[fast])) se.insert(arr[fast++]);
        else se.erase(arr[slow++]);
        // 同过加减元素 保证哈希集中的值不重复
        se.size() > result ? result = se.size() : result;
        // 计算保存每个窗口的大小
      }
      return result;
    }
};

int main () {

  return 0;
}