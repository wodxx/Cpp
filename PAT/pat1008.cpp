#include <iostream>
#include <string>
#include <cstring>
using namespace std;
//输入一个输入项，处理一个输入项

int main () {
  int n, floor;
  int temp = 0;                         //[知识点] 当前值替代法，计算后为保留当前值，可以把该值赋给一个temp变量
  int sum = 0; 
  cin >> n;       //先输入list长度
  for (int i = 0; i < n; i++) {
    cin >> floor;                       //先输入的一个数是楼层的层数 后面的是3个楼层号
    if (floor > temp) {
      sum += (floor - temp) * 6;        //判断前后两个输入值的大小来选择计算方式
    } else if (floor < temp) {
      sum += abs(floor - temp) * 4;
    }
    temp = floor;
  }
  sum = sum + 5 * n;
  cout << sum << endl;
}