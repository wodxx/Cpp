#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

int arr[] = {};
int s[] = {0};

int main(){
    int n;
    cin>>n;
    cin>>arr[1];
    //先給出第一個值，賦初值
    s[1] = arr[1];
    int maxx = s[1];

    //dp
    for(int i = 2; i <= n; i++){
        cin>>arr[i];
        s[i] = max((s[i - 1] + arr[i]), arr[i]);
        maxx = max(s[i], maxx);
    }
    
    cout<<maxx<<endl;
    return 0;
}