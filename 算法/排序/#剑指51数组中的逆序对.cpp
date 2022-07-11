#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int count = 0;
public:
  int reversePairs(vector<int>& nums) { 
    merge(0, nums.size() - 1, nums);
    return count;
  }
  void merge(int left, int right, vector<int>& nums) {
    if (left < right) {
      int mid = left + ((right - left) >> 1);
      merge(left, mid, nums);
      merge(mid + 1, right, nums);
      mergesort(left, right, mid, nums);
    }
  }
  void mergesort(int left, int right, int mid, vector<int>& nums) {
    vector<int> temp(right - left + 1);
    int i = left; 
    int j = mid + 1;                            //两个数组的开头
    int index = 0;                              //数组temp的索引
    while (i <= mid && j <= right) {
      if (nums[i] <= nums[j]) {
        temp[index++] = nums[i++];
      } else {
        count += mid - i + 1;  
        temp[index++] = nums[j++];              //此时，如果第一个数组的当前值
      }                                         //大于第二个数组的但前值，第一个数组此后的数
    }                                           //都与第二个数组当前值后的数组成逆序对
    while (i <= mid) {
      temp[index++] = nums[i++];
    }
    while (j <= right) {
      temp[index++] = nums[j++];
    }
    for (int k = 0; k < temp.size(); k++) {
      nums[left + k] = temp[k];                 //将temp数组覆盖到原数组
    }
  }
};

int main () {

  return 0;
}