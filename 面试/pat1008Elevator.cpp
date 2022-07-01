#include <iostream>
#include <string>
#include <cstring>
using namespace std;
//输入一个输入项，处理一个输入项

int main () {
  int n, floor;
  int temp = 0; 
  int sum = 0; 
  cin >> n;       //先输入list长度
  for (int i = 0; i < n; i++) {
    cin >> floor;
    if (floor > temp) {
      sum += (floor - temp) * 6;  
    } else if (floor < temp) {
      sum += abs(floor - temp) * 4;
    }
    temp = floor;
  }
  sum = sum + 5 * n;
  cout << sum << endl;
}