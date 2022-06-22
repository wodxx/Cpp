struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
int num = 0;
public:
  TreeNode* convertBST(TreeNode* root) {
    //搜索树的中序从小到大 反中序为从大到小
    if (root != nullptr) {
      convertBST(root -> right);
      root -> val += num;
      num = root -> val;
      convertBST(root -> left);
      return root;
    }
    return nullptr;
  }
};

int main () {

  return 0;
}