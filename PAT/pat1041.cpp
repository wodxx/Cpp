#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;

int N;
int bets;
int count = 0; 
unordered_map<int, int> m;
vector<int> vec;

int main () {
  cin >> N;
  vector<int> vec(N);               //这里定义数组， 且给出大小N
  for (int i = 0; i < N; i++) {
    cin >> vec[i];                  //直接输入一个数组：切记要给数组的大小N，且在main()里面，不然会出现段错误
    m[vec[i]]++;
  }
  for (int j = 0; j < N; j++) {    //直接遍历 找到哈希表中出现1次的第一个数，辅助给另一个count后break;
    if (m[vec[j]] == 1) {          //这里不用for(auto it = m.begin(); it != m.end() it++) 是为了找出第一个为1的值
      count = vec[j];              //而用上面的写法，因为m里面的值顺序会变，不能找出第一个值为1的元素
      break;
    }
  }
  if (count != 0) {
    cout << count << endl ;
  } else {
    cout << "None" << endl;
  }
  return 0;
}