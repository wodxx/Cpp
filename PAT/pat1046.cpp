#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


// 不能ac的答案
// int main () {
//   int N, M;
//   int i, j;
//   cin >> N;
//   int sum = 0;
//   vector<int> vec(N);
//   for (int i = 0; i < N; i++) {
//     cin >> vec[i];
//     sum += vec[i];
//   }
//   cin >> M;
//   while (M--) {
//     int result = 0;
//     cin >> i >> j;
//     if (i < j ) {
//       for (int index = i - 1; index < j - 1; index++) {
//         result += vec[index];
//       }                             // 连成一圈，求个和，判断好首尾指针
//     } else if (j < i) {
//       for (int index = j - 1; index < i - 1; index++) {
//         result += vec[index];
//       } 
//     } else {
//       result = 0;
//     }
//     cout << min(result, sum - result) << endl;
//   }
//   return 0;
// }

//ac答案
int a[100005], dis[100005];
int main () {
  int N, sum = 0;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    sum += a[i];
    dis[i + 1] = sum;              //计算从1开始到i的距离存入dis数组
  }
  int m, k;
  k = sum / 2;
  cin >> m;
  while (m--) {
    int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    int sum1 = dis[y] - dis[x];   //直接求出两点间的距离
    if (sum1 < k) {
      cout << sum1 << endl;       //距离小于总和的一半直接输出，否则输出与总和的差
    } else { 
      cout << sum - sum1 << endl;
    }
  }
  return 0;
}