//给出一个有序的整数数组 A 和有序的整数数组 B ，请将数组 B 合并到数组 A 中，变成一个有序的升序数组
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void merge(int A[], int m, int B[], int n) {
    // 归并思想 两数组比较
    // 归并后的长度为m + n, 从后往前放置，即先选大值
    // 因为从前往后放置，一次比较不能确定要放置元素的位置
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;   // 合并后A的长度-1
    while (i >= 0 && j >= 0) {
      if (A[i] > B[j]) A[k--] = A[i--];
      else A[k--] = B[j--];
    }
    while (i >= 0) A[k--] = A[i--];
    while (j >= 0) A[k--] = B[j--];
  }
};

int main () {

  return 0;
}