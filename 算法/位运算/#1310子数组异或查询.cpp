#include <bits/stdc++.h>
using namespace std;

//暴力法（超时）
// class Solution {
// public:
//   vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
//     vector<int> results;

//     for (auto i : queries) {
//       int sum = 0;
//       for (int j = i[0]; j <= i[1]; j++) {
//         sum ^= arr[j];
//       }
//       results.push_back(sum);
//     }
    
//     return results;
//   }
// };

//前缀标准和
class Solution {
public:
  vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    vector<int> temp(arr.size());
    vector<int> results;

    temp[0] = arr[0];                      //第一个数异或值为自身
    for (int i = 1; i < arr.size(); i++) {
      temp[i] = temp[i - 1] ^ arr[i];    //定义一个数组，把arr中每个值之前的异或值存储
    }                                    //动态规划
    for (auto i : queries) {
      if (i[0] == 0) results.push_back(temp[i[1]]);//queries中数组左值为0，直接为计算好的arr[queries右值]的异或值
      else {
        results.push_back(temp[i[0] - 1] ^ temp[i[1]]);//左值不为0，用右值前的异或抵去左值前的异或值为所求区间所有值的异或(异或的性质：相同抵消)
      } 
      
    }

    return results;
  }
};

int main () {

  return 0;
}