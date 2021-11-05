#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
      //if(k > arr.size()) return;
      vector<int> vec;
      //对数组进行排序，选前k个，复杂度nlogn
      sort(arr.begin(), arr.end());
      for(int i = 0; i < k; ++i){
        vec.push_back(arr[i]);
      }
      return vec;
    }
};

int main(){
  return 0;
}