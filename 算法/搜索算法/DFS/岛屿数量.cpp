// 描述
// 给一个01矩阵，1代表是陆地，0代表海洋， 如果两个1相邻，那么这两个1属于同一个岛。我们只考虑上下左右为相邻。
// 岛屿: 相邻陆地可以组成一个岛屿（相邻:上下左右） 判断岛屿个数。
// 例如：
// 输入
// [
// [1,1,0,0,0],
// [0,1,0,1,1],
// [0,0,0,1,1],
// [0,0,0,0,0],
// [0,0,1,1,1]
// ]
// 对应的输出为3
// (注：存储的01数据其实是字符'0','1')

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void dfs(vector<vector<char>>& grid, int i, int j) {
    grid[i][j] = '0';                            // 岛屿周围的岛屿用‘0’(海)表示
    if (i - 1 >= 0 && grid[i - 1][j] == '1') dfs(grid, i -1, j);
    if (i + 1 < grid.size() && grid[i + 1][j] == '1') dfs(grid, i + 1, j);
    if (j - 1 >= 0 && grid[i][j - 1] == '1') dfs(grid, i, j - 1);
    if (j + 1 < grid[0].size() && grid[i][j + 1] == '1') dfs(grid, i, j + 1);
  }                                             // 注意指针0可以取到，应该是>=0;
  int solve(vector<vector<char> >& grid) {
    int count = 0;
    int row = grid.size();
    int col = grid[0].size();
    if (row == 0 && col == 0) return count;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (grid[i][j] == '1') {
          count++;                              // 有字符1记为一个岛屿
          dfs(grid, i, j);
        }  
      }
    }
    return count;
  }
};

int main () {

  return 0;
}


#include <bits/stdc++.h>
using namespace std;
int N, M;
int x = 0, y = 0;
int T = 0, count = 0;
uint8_t grid[10000][10000];

void dfs (uint8_t grid[][], int i, int j, int count) {
  if (i - 1 > 0 && abs(grid[i - 1][j] - grid[i][j]) < T) {
    count++;
    dfs(grid, i - 1, j, count);
  }
  if (i + 1 < N && abs(grid[i + 1][j] - grid[i][j]) < T) {
    count++;
    dfs(grid, i + 1, j, count);
  }
  if (j - 1 > 0 && abs(grid[i][j - 1] - grid[i][j - 1]) < T) {
    count++;
    dfs(grid, i, j - 1, count);
  }
  if (j + 1 < M && abs(grid[i][j + 1] - grid[i][j + 1]) < T) {
    count++;
    dfs(grid, i, j + 1, count);
  }
}
int main () {
  cin >> N >> M >> x >> y >> T;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> grid[i][j];
    }
  }
  dfs(grid, x, y, 0);
  cout << count << endl;
}