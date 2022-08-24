#include <bits/stdc++.h>
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
public:
  int judge(TreeNode* root) {
    if (root == nullptr) return 0;
    int left = 1 + judge(root -> left);
    int right = 1 + judge(root -> right);
    // 返回的是该子树的左右子节点下的最大深度
    return left > right ? left : right;
  }
  bool IsBalanced_Solution(TreeNode* pRoot) {
    if (pRoot == nullptr) return true;
    // 分别得到左右子树的深度
    int l = judge(pRoot -> left);
    int r = judge(pRoot -> right);
    if (abs(l - r) > 1) return false;
    // 逐个以每个节点为 头节点 遍历其左右子节点的情况
    return IsBalanced_Solution(pRoot -> left) && IsBalanced_Solution(pRoot -> right);
  }
};

int main () {

  return 0;
}