//题目给出 一个两位数N，要转换成13进制数
//当N取模13得到的余数大于等于10时，分别用A代表10，用B代表11，用C代表12
//一个数N取模K,得到的最小余数为0，即整除，最大余数为K-1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<char> vec;                          //易错！！！！！！！数组类型为字符型
char color[13] = {'0','1','2','3','4','5','6','7','8','9','A','B','C'};    //模13后的余数用一个字符数组来表示

int main () {
  cout << "#";
  for (int i = 0; i < 3; i++) {
    cin >> N;
    if (N == 0) {
      cout << "00";                         //连着输出两个0，则用字符串表示两个0
      continue;
    }
    while (N) {
      vec.push_back(color[N % 13]);        //余数的代表值推入数组
      N /= 13;
    }
    reverse(vec.begin(), vec.end());      //数组翻转输出（根据短除法，最后一个余数在数组的末尾，而按进制转换后的数应该从最后往前数）
    if (vec.size() == 1) cout << 0 ;
    for (auto i : vec) {
      cout << i;
    }
    vec.clear();
  }
}