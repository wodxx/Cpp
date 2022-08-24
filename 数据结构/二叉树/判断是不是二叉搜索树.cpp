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
public:
  bool isValidBST(TreeNode* root) {
   // 迭代遍历，用last记录上一个节点的地址
   // 用迭代解中序遍历的方法 加入一个last节点作为判断
    if (root == nullptr) return false;
    stack<TreeNode* > que;
    TreeNode* cur = root;
    TreeNode* last = nullptr;
    while (cur != nullptr || !que.empty()) {
      if (cur != nullptr) {
        que.push(cur);
        cur = cur -> left;
      } else {
        cur = que.top();
        que.pop();
        if (last) {
        // last存在的情况下 当前节点的值小于等于last节点的值则返回false
          if (cur -> val <= last -> val) return false;
        }
        last = cur;
        cur = cur -> right;
      }
    }
    return true;
  }
};

int main() {
  return 0;
}