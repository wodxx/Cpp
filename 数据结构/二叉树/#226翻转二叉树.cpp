#include <iostream>
using namespace std;

int main(){
  struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
};

class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return nullptr;
    TreeNode* temp = root -> left;           //这三条语句是交换语句swap
    root -> left = root -> right;            //等同于swap(root -> left, root -> right);
    root -> right = temp;
    invertTree(root -> left);
    invertTree(root -> right);
    return root;
  }
};

int main () {

  return 0;
}
