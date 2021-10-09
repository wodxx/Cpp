#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {     
    int count = 0;
    
    if(!nums.empty()){
      //注意这里的end值要取到最大长度减一，而不是最大长度
      int first = GetFirstK(nums, 0, nums.size() - 1, target);
      int last = GetLastK(nums, 0, nums.size() - 1, target);
      if(first > -1 && last > -1){
        count = last - first + 1; //这种情况下有目标之的个数求出并返回
        return count;
      } else return 0;
    } else return 0;
    return count;
  }

    //找第一个K
    int GetFirstK(vector<int>nums, int start, int end, int target){
    if(end < start) return -1; 
    int midindex = (start + end)/2;
    //中值等于目标值
    if(target == nums[midindex]){
      if((midindex > 0 && nums[midindex - 1] != target) 
        || midindex == 0) return midindex;
      else {
        end = midindex - 1;
      }
    }
    else if (nums[midindex] > target) {
      end = midindex - 1;
    } else {
      start = midindex + 1;
    }
    //递归
    return GetFirstK(nums, start, end, target);
  }
    
    //找最后一个K
  int GetLastK(vector<int>nums, int start, int end, int target){
    if(end < start) return -1;
    int midindex = (start + end)/2;
    if(target == nums[midindex]){
      if((midindex < (nums.size() - 1) && nums[midindex + 1]!= target)
        || midindex == (nums.size() - 1)) return midindex;
      else {
        start = midindex + 1;
      }
    }
    else if(nums[midindex] > target){
      end = midindex - 1;
    } else {
      start = midindex +1;
    }
    return GetLastK(nums, start, end, target);
  }   

};

int main(){
  return 0;
}