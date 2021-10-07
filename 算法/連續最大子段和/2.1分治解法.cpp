#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
int arr[] = {};

int Midfind(int left, int right){
    if (left == right) return left;
    int mid = (left + right)/2;

    //左半部分求和
    int sum1 = 0;
    int maxx1 = INT_MIN;
    for(int i = mid; i >= left; i--){
        sum1 += arr[i];
        maxx1 = max(sum1, maxx1);
    }

    //右半部分求和
    int sum2 = 0;
    int maxx2 = INT_MIN;
    for(int j = mid + 1; j <= right; j++){
        sum2 += arr[j];
        maxx2 = max(sum2, maxx2);
    }

    //遞歸
    return max(max(Midfind(left, mid), Midfind(mid + 1 , right)), 
    maxx1 + maxx2 - arr[mid]);
}
int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
    }
    cout<<Midfind(1,n)<<endl;
    return 0;
}