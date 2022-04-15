#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    int len1 = nums1.size();
    int len2 = nums2.size();

    vector<vector<int>> dp(len1 + 1, vector<int> (len2 + 1, 0));
    int max_len = 0;
    //dp[i][j] ：以下标i - 1为结尾的A，和以下标j - 1为结尾的B，最长重复子数组长度为dp[i][j]
    for(int i = 1; i <= len1; i++) {
      for(int j = 1; j <= len2; j++) {
        if(nums1[i - 1] == nums2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = 0;                     //当不相等时，值为0
        }
        max_len = max(max_len, dp[i][j]);
      }   
    }

    return max_len;
  }
};
int main(){

  return 0;
}