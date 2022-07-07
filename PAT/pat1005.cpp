#include <iostream>
#include <string>
const int maxn = 105;
#include <cstring>
using namespace std;
char N[maxn];                   //定义的是一个字符型树组，12345不当作一个整数输入
char res[5];
int count = 0;
const string num[10] = {"zero", "one", "two", "three", "four", "five",
  "six", "seven", "eight", "nine"};

//知识点： 字符对应取字符串数组中的字符串元素
int main () {
  cin >> N; 
  int sum = 0;
  for (int i = 0; i < strlen(N); ++i) {
    sum += N[i] - '0';
  }
  if (sum == 0) {
    cout << "zero" <<endl;
    return 0;
  }
  while (sum) {
    res[count++] = sum % 10;     //除以10取每一位的值 从低位开始
    sum /= 10;                   //去除低位后的sum
  }
  for (int i = count - 1; i >= 0; --i) {
    cout << num[res[i]];         //输出对应位的字符串
    if (i) cout <<' ';           //当i等于0时，这时便不再输出空格
  }
  return 0;
}