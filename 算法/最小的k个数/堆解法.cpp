#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  vector<int> getLeastNumbers(vector<int>& arr, int k) {
    vector<int> vec;
    if(k == 0) return vec;
    priority_queue<int> que;
    for(int i = 0; i < k; ++i){
      que.push(arr[i]);
    }  
    //从k+1个数在大根堆中开始比较
    //堆顶元素最大
    for(int i = k; i < arr.size(); ++i){
      if(que.top() > arr[i]){
        que.push(arr[i]);
        que.pop();
      }
    }
    //前k个值推入数组vec
    for(int i = 0; i < k; ++i){
      vec.push_back(que.top());
      que.pop();
    }
    return vec;
  }
};

int main(){
  return 0;
}