// 给出一个整型数组 numbers 和一个目标值 target，请在数组中找出两个加起来等于目标值的数的下标，
// 返回的下标按升序排列。
// （注：返回的数组下标从1开始算起，保证target一定可以由数组里面2个数字相加得到）
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param numbers int整型vector 
     * @param target int整型 
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
      // write code here
      map<int, int> m;
      vector<int> result;
      for (int i = 0; i < numbers.size(); i++) {
        m[numbers[i]] = i + 1;
      }
      for (int j = 0; j < numbers.size(); j++) {
        int diff = target - numbers[j];
        if (m.find(diff) != m.end() && j + 1 != m[diff]) {
          result.push_back(m[diff]);
          result.push_back(j + 1);
          break;
        } 
      }
      sort(result.begin(), result.end());
      return result;
    }
};