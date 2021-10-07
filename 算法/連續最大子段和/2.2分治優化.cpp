#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
int arr[] = {};
int s[] = {0};
int maxx = INT_MIN;

int Midfind(int left, int right){
    if (left == right) return left;
    int mid = (left + right)/2;

    //計算含mid的子段和
    for(int i = left; i <= mid; i++){
        for(int j = mid ; j <= right; j++){
            int sum = s[j] - s[i] + arr[i];
            maxx = max(sum, maxx);
        }
    }

    //遞歸
    return max(max(Midfind(left, mid), Midfind(mid + 1 , right)), maxx);
}
int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        s[i] = s[i - 1] + arr[i];
    }
    cout<<Midfind(1,n)<<endl;
    return 0;
}

//有問題，需調試