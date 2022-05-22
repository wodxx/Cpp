#include <bits/stdc++.h>
using namespace std;

//排序
class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;
    sort(nums.begin(), nums.end());
    int results = 1;
    int maxx = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i - 1] == nums[i]) {      //2,相邻两值相等，results=1后continue
        continue;                        //相等的情况不中断results，即results不归为1
      }
      if (nums[i - 1] + 1 == nums[i]){   //排序后两种情况：1，当前值加1等于下一个元素
        results++;    
        maxx = max (results, maxx);     //维护一个maxx，保存最大的连续数
      } else {                          //如果下一个比前一个大1以上，则results=1后继续
        results = 1;
      }                               
    }
    return maxx;
  }
};

//set
class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int results = 0;
    unordered_set<int> s;
    for (auto i : nums) s.insert(i);
    for (auto j : s) {
      if (s.count(j - 1)) continue;       //当前元素的前一个存在，则从下一个开始
      int count = 0;
      while (s.count(j)) {
        j++;
        count++;                          //j的下一个存在即加一，计数count加1
      }
      results = max(results, count);
    }
    return results;    
  }
};

int main () {

  return 0;
}
