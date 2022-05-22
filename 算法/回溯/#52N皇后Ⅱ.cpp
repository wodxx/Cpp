#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool check(vector<int>& queenPos, int i, int j) {
    for (int k = 0; k < i; k++) {
      if (queenPos[k] == j || abs (queenPos[k] - j) == abs (k - i)) {
        return false;
      }
    }
    return true;
  }
  int find (vector<int>& queenPos, int i, int n) {
    if (i == n) return 1;                      //求值（个数）数据类型用int
    int results = 0;
    for (int j = 0; j < n; j++) {
      if (check (queenPos, i, j)) {
        queenPos[i] = j;
        results += find (queenPos, i + 1, n);
      }
    }
    return results;
  }
  int totalNQueens(int n) {
    if (n < 1) return 0;
    vector<int> queenPos(n);         //这里要写数组大小
    return find (queenPos, 0, n);
  }
};

int main () {

  return 0;
}