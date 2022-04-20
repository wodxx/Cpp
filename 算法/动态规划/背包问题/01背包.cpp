#include <iostream>                                             
#include <cmath>
#include <vector>
using namespace std;

int main(){
  int n = 4, V = 2;
  vector<int> weight = {0, 1, 1, 1, 2};
  vector<int> value = {0, 1, 2, 3, 4};
  int dp[5][3];
  //dp[i][j]表示从0-i的物品任取放入容量为j的背包的最大总价值
  dp[5][0] == 0;
  dp[0][3] == 0;

  for(int i = 1; i <= 4; i++){
    for(int j = 1; j <= 2; j++){
      if(j > weight[i]){
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
      }
    }
  }

  cout<<dp[4][2]<<endl;
  return 0;
}