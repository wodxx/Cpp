#include <bits/stdc++.h>
using namespace std;

//hash
class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> results;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
      m[nums[i]]++;
    }
    for (int i = 1; i <= nums.size(); i++) {
      if (m[i] == 0) results.push_back(i);      //遍历(1-n),从m中找出值为0的
    }                                        //哈希表像python中的字典，可以给一个键，询问该键的
    return results;                         //值，如果值为0则说明没有该键
  }
};

//抽屉算法
class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    int i = 0;
    while (i < nums.size()) {                   //抽屉算法
      if (nums[nums[i] - 1] != nums[i]) {     //某一下标的值是否等于该下标加1后的值，不等于则
        swap (nums[nums[i] - 1], nums[i]);   //把该值放在其值减1的下标位置
      } else {
        i++;
      }
    }
    vector<int> results;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != i + 1) {
        results.push_back(i + 1);
      }
    }
    return results;
  }
};

int main () {

  return 0;
}