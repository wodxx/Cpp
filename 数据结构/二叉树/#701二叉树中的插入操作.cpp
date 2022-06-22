#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {    
      TreeNode* node = new TreeNode(val);
      if (root == nullptr) return node;   //给一个节点赋子节点：直接返回
      if (val > root -> val) root -> right = insertIntoBST(root -> right, val);
      else root -> left = insertIntoBST(root -> left, val);
      return root;
    }
};

int main () {

  return 0;
}