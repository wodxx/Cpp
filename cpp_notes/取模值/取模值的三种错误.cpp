/*
 * @Author: your name
 * @Date: 2021-10-20 16:49:24
 * @LastEditTime: 2021-10-20 17:16:33
 * @FilePath: /Cpp/cpp_notes/ 取模值/取模值的三种错误.cpp

  [问题]为什么很多题目要求对答案1e9+7取模？
  1.1000000007是一个质数
  2.int32位的最大值为2147483647，所以对于int32位来说1000000007足够大
  3.int64位的最大值为2^63-1，对于1000000007来说它的平方不会在int64中溢出，
  所以在大数相乘的时候，因为(a∗b)%c=((a%c)∗(b%c))%c，所以相乘时两边都对1000000007取模，
  再保存在int64里面不会溢出

*/

#include <iostream>
using namespace std;

//错误一：用max函数来比较几个数中的大数时，先行取模  

//正确做法：在求max的时候不要先取mod，而是都以long long型数据比大小，
//最后得到最大值是2e9 + 7，再对它取mod，得到结果是1e9 + 7

LL Treesum(TreeNode * root){
  if (!root)  return 0;
  LL left = Treesum(root -> left);
  LL right = Treesum(root -> right);
  LL subsum = left + right + root -> val;
  //下面不呢先对subsum取模，应该在返回rmax时取模
  rmax = max(rmax, (Total -subsum) * subsum % mod);
  return rmax;

  // return rmax % mod;
}

//错误二：直到return时才取模
//如果让你算1+2+…+n的值（由于答案可能很大，输出结果请对1e9+7取）
//n的取值范围是1 ~ 10^10000
//那显然如果你在中间过程中不先取mod，必然会爆数据范围，因为不管是int还是long long，
//甚至是doubl都无法存下这个数据

long long res = 0;
for(int i = 1; i <=n; i++){
  res = res + i;//如果不在此时取模，n巨大，res无法存下这个数据
  //正确： res = (res + i) % (le9 +7);
} //这里注意，如果使用 += 符号，防止对i单独取模

return res % (le9 +7)

//正确做法：在算res的过程中取模
//解释，错误一和二并不矛盾：
//错误1是在比较多个很大的数据（不超过long long）
//错误2是在维护1个很大的数据，那你先取模和后取模，就没有区别了，因为结果都是一样的

int main(){
  return 0;
}