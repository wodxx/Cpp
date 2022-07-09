#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
bool used[1000101];


///用一个used[]布尔树组存储第二个字符串
// int main () {
//   string s1, s2;
//   int number = 0;
//   getline(cin, s1);                 //getline() 该函数可以读取整行，包括前岛和嵌入的空格
//   getline(cin, s2);
//   for (auto i : s2) {
//     number = i;
//     used[number] = true;
//   }
//   for (auto j : s1) {
//     number = j;
//     if (!used[j]) {
//       cout << j;
//     }
//   }
//   return 0;
// }


///哈希
int main () {
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);         
  set<char> set1;
  for (auto i : s2) {          //输入的字符串能够直接操作
    set1.insert(i);
  }
  for (auto j : s1) {
    if (!set1.count(j)) {
      cout << j;               //s1中未在s2中出现的输出
    }
  }
  return 0;
}