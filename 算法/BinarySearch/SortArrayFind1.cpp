//在一个有序数组中找出目标值

#include <iostream>
using namespace std;
int arr[] = {};

int findtarget(int low, int high, int target){
  while(low <= high){
    int mid = (low + high)/2;
    if(target == arr[mid]) return mid;
    //注意这里变动的是指针high，low，mid
    else if(target < arr[mid]) high = mid - 1;
    else low = mid + 1;
  }
  return -1;
}

int main(){
  int n, m;
  cout<<"tell me szie of your Sort-array : "<<endl;
  cin>>n;
  cout<<"tell me your Sort-array: "<<endl;
  for(int i = 0; i < n; i++){
    cin>>arr[i];
  }
  cout<<"tell me your target : "<<endl;
  cin>>m;

  int index = findtarget(0, n-1, m);
  if(index != -1){
    cout<<"Find it!"<<endl;
    cout<<index<<endl;
  } else {
    cout<<"Not found!"<<endl;
  }
  return 0;
}