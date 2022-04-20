#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<int> coins = {0, 1, 2, 5, 10, 20, 50, 100, 200};
  int sum = 200;
  int dp[9][201];

  dp[9][0] == 1;            //边界条件
  dp[0][200] == 0;

  for(int i = 1; i <= 8; i++){
    for(int j = 1; j <= sum; j++){
      for(int k = 0; k <= j / coins[i - 1]; k++){   // 这里k是从0算起，因此为i-1
        dp[i][j] += dp[i - 1][j - k * coins[i - 1]];    // 算系数k的问题
      }
    }
  }

  cout<<dp[8][200]<<endl;
  return 0;
}