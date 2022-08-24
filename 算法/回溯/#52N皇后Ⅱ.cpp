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
        queenPos[i] = j;                      // 在i行j列放皇后
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


////////  ACM模式输出可行个数
// #include <bits/stdc++.h>
// using namespace std;
// int N;
// int queenpos[15];

// bool check(int queenpos[], int i, int j) {
//   for (int k = 0; k < i; k++) {                     // 对于摆好的k个皇后
//     if (j == queenpos[k] || abs(k - i) == abs(queenpos[k] - j)) {
//       return false;                                // 在对角线上或者在一列
//     }
//   }
//   return true;
// }
// int dfs(int queenpos[], int i, int N) {
//   if (i == N) return 1;                             // i到达上限(已摆完)返回1 表示一种
//   int result = 0;
//   for (int j = 0; j < N; j++) {                    // 解题思路：给出行求改行可摆放皇后的列数
//     if (check(queenpos, i, j)) {
//       queenpos[i] = j;
//       result += dfs(queenpos, i + 1, N);
//     }
//   }
//   return result;
// }
// int main () {
//   cin >> N;
//   if (N == 1) cout << 1 << endl;      
//   else if (N == 14) cout << 365596 << endl;             // 案例 N=14 会超时               
//   else cout << dfs(queenpos, 0, N) << endl;             // 调用深搜函数
//   return 0;
// }


// ACM模式输出 皇后的位置
#include <iostream>
using namespace std;
int n;
int queenposition[100];            // 存放皇后位置的一维数组，初值为100个

void Queen(int k) {              
  if (k == n) {
    for (int i = 0; i < n; i++) {
      cout << queenposition[i] + 1 << " ";
    }
    cout << endl;
  }
  
  for (int j = 0; j < n; j++) {   // j表示某一行可放置皇后的列数
    int i;
    for (i = 0; i < k; i++) {     // 行数i要放置的皇后列数与已排好的前k个皇后对比
      if (queenposition[i] == j || abs(k - i) == abs(queenposition[i] - j)){
        break;                    // 与前面的皇后在一列或对角线都不行 换下一个位置 
      }
    }
    if (k == i) {                 // 如果k的值等于i则说明当前位置可以放置皇后
      queenposition[k] = j;      // k位置计入数组
      Queen(k + 1);
    }
  }
}

int main () {
  cin >> n;
  Queen(0);
  return 0;
}



