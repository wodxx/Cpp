//输入一个整数N，一个数d,按进制d转换，判断转换后的数字是不是回文
//再反向输出转换后的数

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;                              //考点： 一个整数按d进制转换
int N, d;                                         //数组赋值给另一个数组
vector<int> nums;

int main () { 
  cin >> N;
  cin >> d;
  while (N) {                                      //整数N按进制d转换存入数组
    nums.push_back(N % d);
    N /= d;
  }
  vector<int> temp = nums;                        //将转换后的数组nums赋值给一个新数组temp
  reverse(temp.begin(), temp.end());              //新数组此时和nums相同，再进行reverse翻转操作
  if (temp == nums) {                             //进行翻转操作后如果新旧数组仍然相同则为回文数字
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  int len = nums.size();
  for (int j = len - 1; j >= 0; j--) {
    cout << nums[j];
    if (j != 0) {                                 //输出带空格的 写法
      cout << " ";   
    }
  }
  return 0;
}