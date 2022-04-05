/*
 * @Author: your name
 * @Date: 2021-10-17 17:09:37
 * @LastEditTime: 2021-10-17 17:18:28
 * @LastEditors: Please set LastEditors
 * @Description: 剑指第3题
 * @FilePath: /Cpp/算法/数组中重复的数/findRepeatNumber.cpp
  [理解]
  题目说明尚未被充分使用，即 在一个长度为 n 的数组 nums 里的所有数字都在 0 ~ n-1 的范围内 。
  此说明含义：数组元素的 索引 和 值 是 一对多 的关系。
  因此，可遍历数组并通过交换操作，使元素的 索引 与 值 一一对应（即 nums[i] = inums[i]=i ）。
  因而，就能通过索引映射对应的值，起到与字典等价的作用。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
      if (nums.empty()) return -1;
      int i = 0;
      while(i < nums.size()){
        if(nums[i] == i){
          i++;//判断i增加到索引和索引对应的数组值不同为止
          continue;
        }
        //如果此时在排序后出现下面等式则说明出现相同的值
        if(nums[nums[i]] == nums[i]){
          return nums[i];
        } else {
          //将i对应值作为索引值对应的值与i的索引值对换
          //即将i对应的值放到他的位置上
          swap(nums[nums[i]], nums[i]);
        }
      }
      return -1;
    }
};

int main(){

  return 0;
}
