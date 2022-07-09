#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main () {
  int M, N;
  cin >> M >> N;
  int max = 0, result = 0;
  int value;
  unordered_map<int, int> m;
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      cin >> value;
      m[value]++;
    }
  }
  for (auto it = m.begin(); it != m.end(); it++) {  //哈希
    if (it -> second > max) {
      max = it -> second;
      result = it -> first;
    }
  }
  cout << result << endl;
}