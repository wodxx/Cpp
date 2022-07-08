///下面的解法不能AC
// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;
// string str;
// vector<char> vec;

// int main () {
//   cin >> str;
//   int N = str.size();
//   for (int i = 0; i < N; i++) {
//     vec.push_back(str[i]);
//   }
//   if (N % 2 != 0) {
//     int i = 0, j = N - 1;
//     while ()) {
//       cout << vec[i] << "   " << vec[j] << endl;
//       i++;
//       j--;
//     }
//     for (int m = i; m <= j; m++) {
//       cout << vec[m];
//     }
//   }
//   if (N % 2 == 0) {
//     int i = 0, j = N - 1;
//     while (j - i != 3) {
//       cout << vec[i] << "  " << vec[j] << endl;
//       i++;
//       j--;
//     }
//     for (int m = i; m <= j; m++) {
//       cout << vec[m];
//     }
//   }
//   return 0;
// }


//AC答案 本题要求n1=n3<=n2
// 因为n1 +n2 +n​3​​ −2 = N，所以n2 = N + 2 - n1 - n3 = N + 2 - 2n1
// 因为n2 >= n1，所以N + 2 - 2n1 >= n1，即3n1 <= N + 2
// 得n1 <= (N + 2) / 3

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int n1, n2, len = str.size();
	n1 = (len + 2) / 3;
	n2 = len - 2 * n1 + 2;
	int left = 0, right = str.size() - 1;
	for (int i = 0; i < n1 - 1; i++)
	{
		cout << str[left++];
		for (int j = 0; j < n2 - 2; j++) //n2 - 2是中间的空格数
			cout << ' ';
		cout << str[right--] << endl;
	}
	for (int i = left; i <= right; i++)
		cout << str[i];
	system("pause");
	return 0;
}
