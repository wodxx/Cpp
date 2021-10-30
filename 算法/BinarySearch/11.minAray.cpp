/*
找出数组中的最小值！
剑指offer-NO11:
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。 
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
      int i = 0; 
      int j = numbers.size() - 1;                   
      int mid = i;                                      //这里初始化mid为i，一旦发现numbers[i]为最小，直接返回
      while(numbers[i] >= numbers[j]){                  //递增数组的旋转数组第一个数有可能大于等于第二个数                                                        
        if(j - i == 1){                                 //该题二分法的指针移动到相邻位置   
          mid = numbers[j];                             //旋转数组有两个递增数列，循环到第二个递增数列的首元素
          break;
       }
        numbers[mid] = (numbers[i] + numbers[j])/2;     
        if(numbers[mid] >= numbers[i])  i = mid;        //与第一个数对比，大于等于则位于前面的递增数列，mid赋值给i   
        if(numbers[mid] <= numbers[j])  j = mid;        //与最后一个数对比，小于等于则位于后面的递增数列，mid赋值给j
      }
      return numbers[mid];
    }
};

int main(){

  return 0;
}