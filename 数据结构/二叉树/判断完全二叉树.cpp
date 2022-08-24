#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  bool isCompleteTree(TreeNode* root) {
  // 层序遍历 利用完全二叉树条件
    if (root == nullptr) return true;
    queue<TreeNode* > que;
    que.push(root);
    while (!que.empty()) {
      TreeNode* cur = que.front();
      que.pop();
      if (cur != nullptr) {
        // 完全二叉树条件1：有右无左 返回false
        if (cur -> left == nullptr && cur -> right != nullptr)
          return false;
        // cur的左右子节点入队
        que.push(cur -> left);
        que.push(cur -> right);
      } else 
        // 遇到空节点 循环终止
        break;
    }
    // 二次while判断不满足上述条件1（左无右有）后仍有不满足：
    // 条件2 完全二叉树叶子节点须从左至右依次排列
    // 队列还为空 如果头结点非空 则返回false 空则出队
    while (!que.empty()) {
      if (que.front() != nullptr) return false;
      else que.pop(); 
    }
    return true;
  }
};

int main () {

  return 0;
}