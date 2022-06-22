#include <iostream>
using namespace std;

int main(){
  struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
};

class Solution {
int results = 0;
public:
  int diameterOfBinaryTree(TreeNode* root) {
    if (root == nullptr) return 0;
    callength(root);
    return results;
  }
  int callength(TreeNode* cur) {
    if (cur == nullptr) return 0;
    int l = callength(cur -> left) + 1;
    int r = callength(cur -> right) + 1;
    results = max(l + r - 2, results);        //求左右子树的深度之和取最大值
    return max(l, r);                         //单个子树+1，在求和时-2
  }
};
