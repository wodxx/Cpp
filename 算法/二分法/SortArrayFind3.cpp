#include <iostream>
#include <time.h>
#include <limits.h>
#include <algorithm>
#include <stdlib.h>
#define MAX 11
using namespace std;

int nums[MAX];
//随机取一组值
void inputArray(int nums[]){
  srand((unsigned)time(NULL));
  for(int i = 0; i < MAX ; i++){
    nums[i] = rand() % 10;
    cout<<" "<<nums[i];
  }
}
//输出数组
void outputArray(int nums[]){
  for(int i = 0; i < MAX; i++){
    cout<<" "<<nums[i];
  }
}
//快排
int Quicksort(int low, int high, int nums[]){
  int tempkey = nums[low];
  nums[0] = tempkey;
  while(low < high){
    while(low < high && nums[high] >= tempkey) high--;
    if(low < high) nums[low] = nums[high];
    while(low < high && nums[low] <= tempkey) low++;
    if(low < high) nums[high] = nums[low];
  }
  nums[low] = nums[0];
  return low;
}
//整体排序
void sortnums(int low, int high, int nums[]){
  if(low < high){
    //分段位置的下表值
    int index = Quicksort(low, high, nums);
    sortnums(low, index - 1, nums);
    sortnums(index + 1, high, nums);
  }
}
//二分查找
int binarysearch(int low, int high, int K){
  while(low <= high){
    int mid = (low + high)/2;
    if(K == nums[mid]) return mid;
    else if(K < nums[mid]) high = mid -1;
    else low = mid + 1;
  }
  return -1;
}

int main(){
  int K, result;
  cout<<"Befor sort :"<<endl;
  //outputArray(nums);
  inputArray(nums);
  cout<<endl;
  cout<<"After sort :"<<endl;
  sortnums(0, MAX - 1 , nums);
  outputArray(nums);
  cout<<endl;
  cout<<"The number you want to find :"<<endl;
  cin>>K;
  result = binarysearch(0, MAX - 1, K);
  if(result != -1){
    cout<<"Found it!"<<"  "<<result<<endl;
  } else {
    cout<<"Not Found!"<<endl;
  }
  return 0;
}