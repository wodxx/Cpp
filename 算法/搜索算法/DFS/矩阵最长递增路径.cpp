// 描述
// 给定一个 n 行 m 列矩阵 matrix ，矩阵内所有数均为非负整数。 你需要在矩阵中找到一条最长路径，使这条路径上的元素是递增的。并输出这条最长路径的长度。
// 这个路径必须满足以下条件：

// 1. 对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外。
// 2. 你不能走重复的单元格。即每个格子最多只能走一次。

// 数据范围：1 \le n,m \le 10001≤n,m≤1000，0 \le matrix[i][j] \le 10000≤matrix[i][j]≤1000
// 进阶：空间复杂度 O(nm)O(nm) ，时间复杂度 O(nm)O(nm)

// 例如：当输入为[[1,2,3],[4,5,6],[7,8,9]]时，对应的输出为5

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int result = 0;
public:
  void dfs(vector<vector<int>>& matrix, int row, int col, 
           int i, int j, int max_result) {
    int last_num = matrix[i][j];                         // 记录当前二维值
    matrix[i][j] = -1;                                   // 当前二维值标记为已使用
    if (max_result > result) result = max_result;        // 更新最大值
    if (i - 1 > 0 && matrix[i - 1][j] > last_num && matrix[i - 1][j] != -1) 
      dfs(matrix, row, col, i - 1, j, max_result + 1);
    if (i + 1 < row && matrix[i + 1][j] > last_num && matrix[i + 1][j] != -1) 
      dfs(matrix, row, col, i + 1, j, max_result + 1);
    if (j - 1 > 0 && matrix[i][j - 1] > last_num && matrix[i][j - 1] != -1) 
      dfs(matrix, row, col, i, j - 1, max_result + 1);
    if (j + 1 < col && matrix[i][j + 1] > last_num && matrix[i][j + 1] != -1) 
      dfs(matrix, row, col, i, j + 1, max_result + 1);   // 满足存在条件且满足边界条件且满足题目要求则进行归操作
    matrix[i][j] = last_num;                             // 无符合的值时当前二维值返回到matrix[i][j]
  }
  int solve(vector<vector<int> >& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    if (row == 0  && col == 0) return 0;
    for (int i = 0; i < row; i++) {                     // 从矩阵的每一个值开始
      for (int j = 0; j < col; j++) {
        dfs(matrix, row, col, i, j, 1);
      }
    }
    return result;
  }
};

int main () {

  return 0;
}


// 在矩阵中标记一个值被使用过有两种方法
// 1. 使用used[]数组，常见于回溯算法中，比如全排列问题
// 2. 使用value[i] = -1的形式 常见于在一组参数递过来之后，对该参数-1，常见于二维数组寻找路径等