#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int main(){

    //給出數組
    int n;
    cin>>n;
    int arr[n];
    int s[n] = {0};
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        s[i] = s[i - 1] + arr[i];
    }

    //枚舉
    int maxx = INT_MIN;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            int sum = s[j] - s[i] + arr[i];
            maxx = max(sum, maxx);
        }
    }

    cout<<maxx<<endl;
    return 0;
}

//i-j段的和用s[j]-s[i]+arr[i]來表示
//這裏有一個遍歷循環邊界的問題，即什麼時候取等號的問題？？？？？？？？？？？？？？？？