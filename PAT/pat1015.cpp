#include<bits/stdc++.h>
using namespace std;

int transfer(int n, int d) {                     //将一个数按进制转换成反序
    int nums[100001];                            //按d进制转换
    int j = 0,sum = 0;
    int m = n;
    while (m != 0){
        nums[j++] = m % d;
        m /= d;
    }
    int k = 0;
    for (int i = j - 1; i >= 0;i--) {
        sum += nums[i] * pow(d, k);
        k++;
    }
    return sum;
}

bool judge(int x) {                                //判断素数 
    if (x <= 1) return 0;                          //判断素数前先确定要判断的这个数不是1
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main () {
    int n, d;
    cin >> n;
    while (n >=0 ) {
        cin >> d;
        int x = transfer(n, d);
        if (judge(x) && judge(n)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        cin >> n;
    }
    return 0;
}