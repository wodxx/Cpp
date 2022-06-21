#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
  //变量范围给到uint64_t
  uint64_t count = 0;
public:
  int pathSum(TreeNode* root, uint64_t targetSum) {
    if (root == nullptr) return 0;
    dfs(root, targetSum);
    pathSum(root -> left, targetSum);
    pathSum(root -> right, targetSum);            //一颗二叉树当成两颗树分别调用计算count
    return count;
  }
  void dfs(TreeNode* cur, uint64_t targetSum) {  //对单个树的节点开始计算count的函数
    if (!cur) return;
    if (targetSum - cur -> val == 0) count++;
    dfs(cur -> left, targetSum - cur -> val);
    dfs(cur -> right, targetSum - cur -> val);
  }
};
