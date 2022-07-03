// 本题输入案例：
// 5 3
// 4 8 12 20 40
// 3 11 16 19
// 3 12 16 19
// 10 11 11 11 11 11 11 11 11 11 11
#include <bits/stdc++.h>
using namespace std;
int N, K;
set<int> s;
int olddata[255];
int used[200];


void dfs (int cur, int sum) {
  if (cur == 4) {
    if (sum % 4 == 0) s.insert(sum / 4);    //如果4个数的和是一个整数 存入set
    return;
  }
  for (int i = 1; i <= N; i++) {
    if (!used[i]) {
      used[i] = 1;
      dfs(cur + 1, sum + olddata[i]);
      used[i] = 0;
    }
  }
}
int main () {
  cin >> N >> K;
  for (int i = 1; i <= N; i++) {
    cin >> olddata[i];     //旧图的数据 一共N个                       
  }
  // for (int j = 0; j < K; j++) {                                  //不一定全部先输入，先输入一部分，再运行程序，最后结束输入写输出
  //   cin >> Numnewphoto[j];   //每一张新图的数据个数 共K张新图
  //   for (int i = 0; i < Numnewphoto[j]; i++) {
  //     cin >> newdata[i];     //每一张新图的数据
  //   }
  // }
  dfs(0, 0);
  for (auto i : s) {
    cout << i << " ";
  }
  cout << endl; 
  while (K--) {
    int m; cin >> m;
    int flag = 1;
    for (int i = 1; i <= m; i++) {
      int x;
      cin >> x;
      if (!s.count(x)) flag = 0;        //不存在s里才会把flag置为0
    }
    if (flag) cout << "Yes\n";
    else cout << "No\n";
  }

  return 0;
}


