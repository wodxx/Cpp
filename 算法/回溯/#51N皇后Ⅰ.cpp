#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
vector<vector<string>> results;
vector<string> temp;
public:
  bool checkPos (vector<int>& queenPos, int i, int j) {
    for (int k = 0; k < queenPos.size(); k++) {         //与已确定的前k行皇后的位置依次排除
      if (queenPos[k] == j || abs(queenPos[k] - j) == abs(k - i)) {
        return false;                                  //在同行同列或者对角线位置都不能放置
      }
    }
    return true;
  }
  void backtrack (vector<int>& queenPos, int i , int n) {
    if (i == n) {
      results.push_back(temp);
      return;
    }
    for (int j = 0; j < n; j++) {
      if (checkPos(queenPos, i, j)) {        //第i行，j列是否能放置皇后
        queenPos.push_back(j);
        string str = string(n, '.');         //初始化一个字符串全部为'.'
        str[j] = 'Q';                        //将字符串中第j个元素改为'Q'
        temp.push_back(str);                 //第i行的字符串推进temp数组
        backtrack (queenPos, i + 1, n);      //递归下一行
        temp.pop_back();                     //有一个结果之后归回来清除这两个数组
        queenPos.pop_back(); 
      }
    }
  }
  vector<vector<string>> solveNQueens(int n) {
    vector<int> queenPos;                  //记录皇后位置的数组
    backtrack(queenPos, 0, n);             //从第0行开始
    return results;
  }
};

int main () {
  
  return 0;
}