#include <vector>
#include <iostream>
using namespace std;
int m, n;

int main(){
  vector<vector<int> >dp;

  for(int i = 0; i < m; i++){
    dp[i][0] = 1;                    //这里是赋值，不是等式
  }

  for(int j = 0; j < n; j++){
    dp[0][j] = 1;
  }

  for(int i = 1; i < m; i++){
    for(int j = 1; j < n; j++){
      dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
    }
  }

  return dp[m - 1][n - 1];          //网格相当于二维数组，数组从0开始，所以右下角的位置为（m-1, n-1).
}