#include <bits/stdc++.h>
using namespace std;

// 双端队列
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    int len = nums.size();
    if (len == 0) return result;
    int right = 0;
    deque<int> deq;
    for (int i = right; i < k; i++) {
      while (!deq.empty() && deq.back() < nums[right]) {     //新值大于队列前端元素 前端元素出队
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

//双指针
class Solution {
public:
  vector<int> maxInWindows(const vector<int>& nums, int size) {
    vector<int> result;
    int len = nums.size();
    if (len < size || size < 1) return result; 
    for (int i = 0; i <= len - size; i++) {            // i的最大取值为len-size 确保j指针遍历的窗口大小为size
      int max = nums[i];                               // j的取值范围是滑动窗口，而i只需保证取到最后一个窗口的第一个值就行
      for (int j = i;j < i + size; j++) {              // 窗口里的值依次和第一个值比较大小
        if (nums[j] > max) max = nums[j];
      }
      result.push_back(max);
    }
    return result;
  }
};

int main () {

  return 0;
}