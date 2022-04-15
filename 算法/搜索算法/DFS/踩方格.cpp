/***************************************************************
[题目]
  一个方格矩阵，矩阵边界在无穷远，作如下假设：
  a 每走一步时，只能从当前方格移动一格，走在相邻的方格上;
  b 走过的格子无法走第二次;
  c 只能从北，东，西三个方向走;
  请问：如果允许在方格上走n步（n<20),共有多少种方案。两种走法只要有一步不一样，即被认为是不同方案。
****************************************************************/

#include <bits/stdc++.h>
using namespace std;
int visited[30][50];

int way (int i, int j, int n) {                              
  if (n == 0) return 1;
  visited[i][j] = 1;                         //将起始节点置为1再不能遍历
  int num = 0;

  if (!visited[i - 1][j]) {                  //判断向西的节点是否能遍历(0为false能访问)
    num += way (i - 1, j, n - 1);
  }

  if (!visited[i][j + 1]) {                  //向北
    num += way (i, j + 1, n - 1);
  }

  if (!visited[i + 1][j]) {                  //向东
    num += way (i + 1, j, n - 1);
  }

  visited[i][j] = 0;                         //(i,j)起始点找完了之后重新置为可遍历，以便换个起始点踩方格时不影响
  return num;                                //某一个点开始走n步的总方案为三个方向的方案之和
}

int main () {
  int n;
  cin >> n;
  memset(visited, 0, sizeof(visited));        //将visited数组置为0(所有节点全部为新节点)
  cout << way (0, 25, n) << endl;
  return 0;
}