#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int n;
int nums[N];

void quickSort (int nums[], int left, int right) {
  if (left >= right) return;                                     // 区间里面只有一个数或者没有数

  int mid = nums[(left + right) / 2];
  int i = left - 1; 
  int j = right + 1;

  while (i < j) {
    do i++; while (nums[i] < mid);
    do j--; while (nums[j] > mid);
    if (i < j) swap(nums[i], nums[j]);
  }

  quickSort(nums, left, j);
  quickSort(nums, j + 1, right);
}
int main () {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  quickSort(nums, 0, n - 1);
  for (int i = 0; i < n; i++) 
    cout << nums[i] << " ";
  return 0;
}



