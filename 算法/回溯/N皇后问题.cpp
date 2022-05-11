// [问题]
//   输入一个正整数N,程序输出N皇后问题的全部摆法。
//   行里的第i个数字如果是N，就代表第i行的皇后应该放在第n列。
//   皇后的行列编号都是从1开始算。
// [样例输入]
// 4
// [样例输出]
// 2 4 1 3
// 3 1 4 2

#include <bits/stdc++.h>
using namespace std;
int N;
int queenPos[100];

void Nqueen(int k) {
  if (k == N) {
    for (int i = 0; i < N; i++) {
      cout << queenpos[i] + 1 << " ";                                   //能输出所有的结果
    }
    cout << endl;
    return;
  }
  for (int i = 0; i < N; i++) {                                          //i从0开始，所以能遍历保存所有的结果
    int j;
    for (j = 0; j < k; j++) {
      if (queenPos[j] == i || abs(queenPos[j] - i) == abs(k - j)) {     //(k-j)表示行数之差
        break;                                                          //break终止当前for循环
      }
    }
    if (j == k) {
      queenPos[k] = i;
      Nqueen(k + 1);
    }
  }
}

int main () {
  cin >> N;
  Nqueen(0);
  return 0;
}