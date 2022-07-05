#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    int len = nums.size();
    if (len == 0) return result;
    int right = 0;
    deque<int> deq;
    for (int i = right; i < k; i++) {
      while (!deq.empty() && deq.back() < nums[right]) {    //新值大于队列前端元素 前端元素出队
        deq.pop_back(); 
      }
      deq.push_back(nums[right]);                            //保持前端元素为队列的最大值
      right++;
    }
    result.push_back(deq.front());
    while(right < len) {
      if (deq.front() == nums[right - k]) deq.pop_front();   //保持队列里的元素是窗口里的元素
      while (!deq.empty() && deq.back() < nums[right]) {
        deq.pop_back();
      }
      deq.push_back(nums[right]);
      result.push_back(deq.front());
      right++;
    }
    return result;
  }
};

int main () {

  return 0;
}