#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
string results[3] = {"W","T","L"};
double value[3];
double answer = 1;
int index = 0;

int main () {
  for (int i = 0; i < 3; i++) {
    double maxx = 0;
    for (int j = 0; j < 3; j++) {
      cin >> value[j];
      if (value[j] > maxx) {               //输入一行数，求出最大值
        maxx = value[j];
        index = j;                        //把最大值的索引值赋值给一个index，用index找该值在字符串results中对应的结果
      }    
    }
    cout << results[index] << " ";
    answer *= maxx;                       //先把找出来的三个最大值乘起来
  }
  cout << fixed << setprecision(2) <<(answer * 0.65 - 1) * 2;  //保留n位有效数字的语法：fixed + setprecision(n)
  return 0;
}

//【知识点】
// 1.索引对应查找
// 2.保留n位有效数字的语法：fixed + setprecision(n)