#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int main(){

    //給出數組
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    //枚舉
    int maxx = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            //在算每一段的值前sum必須置爲0
            int sum = 0;
            for(int k = i; k <= j; k++){
                sum += arr[k];    
            }
            maxx = max(sum, maxx);
        }
    }

    cout<<maxx<<endl;
    return 0;
}

// 小結：
//     掌握一組數據的子數組的枚舉方法：
//     即寫出兩個循環；
//     也可以再寫一個內循環求出每一段的和。