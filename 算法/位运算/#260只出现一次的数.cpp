#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
      int x = 0, y = 0;
      int ans = 0, pos = 0;
      vector<int>results;

      for (int i = 0; i < nums.size(); i++) {
        ans ^= nums[i];                                        //全部值作异或操作，结果为ans=x^y
      }

      int temp = ans;                                         
      while ((temp & 1) == 0) {                                //找temp最低位的1需要右移的次数为pos
        temp >>= 1;                                            //终止条件为temp&1不为0；即找到了temp最低位的1
        pos++;
      }

      for (int i = 0; i < nums.size(); i++) {
        if ((nums[i] >> pos) & 1) x ^= nums[i];               //要找的这两个数只有一个在右移pos位后低位为1
      }                                                       //这个数赋值为x x初值为0，任何数与0异或不变 
      y = x ^ ans;                                            //x与ans异或，得到另一个值为y
      results.push_back(x);
      results.push_back(y);
      return results;
    }
};

int main () {
  {;}
  int a = 0, b = 0;
  if (a > b);
  return 0;
}