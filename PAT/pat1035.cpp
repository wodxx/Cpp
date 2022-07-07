#include <iostream>
#include <string>
#include <vector>
using namespace std;
string team;
string pw;
int count = 0;
vector<string> vec;
int N;
int M;

int main () {
  cin >> N;
  M = N;                           
  while (N--) {
    cin >> team;
    cin >> pw;
    string str;                             //新定义一个字符串进行改动
    for (int i = 0; i < pw.size(); i++) {
      if (pw[i] == '1') {
        str += '@';
      } else if (pw[i] == '0') {
        str += '%';
      } else if (pw[i] == 'l') {
        str += 'L';
      } else if (pw[i] == 'O') {
        str += 'o';
      } else {
        str += pw[i];
      }    
    }
    if (str != pw) {
      count++;
      string res = team +  " " + str;         //队名和密码合为一个字符串
      vec.push_back(res);
    } 
    //M++;
  }
  if (count > 0) {
    cout << count << endl;                   //有改动的次数就输出数组里的元素
    for (auto i : vec) {
      cout << i << endl;
    } 
  } else if (count == 0) {
    if (M == 1) {                           //这里注意未改动的数字单复数 is 与 are
      cout << "There is " << M << " account and no account is modified" << endl;
    } 
    if (M > 1) {
      cout << "There are " << M << " accounts and no account is modified" << endl;
    }
  }
  return 0 ;
}