#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countone (int number) {
    int count = 0;
    while (number != 0) {
      number &= (number - 1);
      count++;
    }
    return count;
  }
  vector<int> countBits(int n) {
    vector<int> results(n + 1);
    for (int i = 0; i <= n; i++) {
      results[i] = countone(i);
    }
    return results;
  }
};

//不能对i进行操作，要再初始化一个等于i的数，(位运算分开写)

//不然每次循环之后i都为0，i最多到1就出不去了

int main () {

  return 0;
}