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
      if (value[j] > maxx) {
        maxx = value[j];
        index = j;
      }    
    }
    cout << results[index] << " ";
    answer *= maxx; 
  }
  cout << fixed << setprecision(2) <<(answer * 0.65 - 1) * 2;  //保留n位有效数字的语法：fixed + setprecision(n)
  return 0;
}