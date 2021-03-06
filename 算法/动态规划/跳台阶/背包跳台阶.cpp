/*************************************************************************
[题目]
  一步一个台阶，两个台阶，三个台阶，.......一步最多可以爬k个台阶。问有多少种不同的方法可以爬到楼顶N呢？
  （即每一步都可以选择跳一个台阶，两个，三个，...，最多k个）

[分析]
  1阶，2阶，.... k阶就是物品，楼顶就是背包。
  每一阶可以重复使用，例如跳了1阶，还可以继续跳1阶。
  问跳到楼顶有几种方法其实就是问装满背包有几种方法。

  求装满背包有几种方法，递推公式一般都是dp[i] += dp[i - nums[j]];
  本题呢，dp[i]有几种来源，dp[i - 1]，dp[i - 2]，dp[i - 3] 等等，即：dp[i - j]

[理解]
  某一层台阶的方式数，等于，所有情况的和。

  所有情况包括：第一步一阶(dp[i-1]),第一步两阶(dp[i-2]),...,第一步k阶(dp[i-k])

  那么递推公式为：dp[i] += dp[i - j]

  既然递归公式是 dp[i] += dp[i - j]，那么dp[0] 一定为1，dp[0]是递归中一切数值的基础所在，如果dp[0]是0的话，其他数值都是0了。
**************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int climbStairs(int n,int k) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {                   // 遍历背包
      for (int j = 1; j <= k; j++) {                 // 遍历物品
        if (i - j >= 0) dp[i] += dp[i - j];          //某一层台阶的方式数，等于，所有情况的和。
      }                                              //所有情况包括：第一步一阶(dp[i-1]),第一步两阶(dp[i-2]),...,第一步k阶(dp[i-k])
    }                                                //那么递推公式为：dp[i] += dp[i - j]
    return dp[n];
  }
};
int main(){

  return 0;
}