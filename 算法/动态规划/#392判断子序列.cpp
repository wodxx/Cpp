#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
      int len1 = s.size();
      int len2 = t.size();

      int i = 0, j = 0;
      while(i < len1 && j < len2){
        if(s[i] == t[j]) i++, j++;
        else j++;
      }

      return i == len1 ;                   //在s里的最后一个元素被匹配到后，i++到len1循环截至
    }                                      //bool类型直接返回一个等式
};

int main() {

  return 0;
}