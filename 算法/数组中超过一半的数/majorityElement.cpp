#include <iostream>
using namespace std;

int arr[] = {1, 1, 1, 2, 1, 1, 5, 4, 2};
int result = arr[0];

void majorityElement(int arr[]){

  int times = 1;                    //给数组的第一个值赋次数1
  int len = sizeof(arr);

  for(int i = 1; i < len; ++i){
    if(times == 0){
      result = arr[i];
      times = 1;
    } else if(arr[i] == result){
      times++;
    } else {
      times--;
    }
  }
}

int main(){
  
  majorityElement(arr);
  cout<<result<<endl;
  return 0;
}