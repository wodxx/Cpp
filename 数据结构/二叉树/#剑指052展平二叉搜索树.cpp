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
  TreeNode* newroot = nullptr;                   //新指针
  TreeNode* pre = new TreeNode(-1);             //新节点
public:
  TreeNode* increasingBST(TreeNode* root) {
    if (root == nullptr) return nullptr;
    inorder(root);                              //定义一个pre节点,把当前节点接上去
    return newroot;                             //指针newroot作记录 cur刚开始为最小的节点 
  }                                             //最后全部遍历完返回newroot即可得到结果
  void inorder(TreeNode* cur) {
    if (cur == nullptr) return;                  //中序遍历为空时 归操作
    inorder(cur -> left);

    if (newroot == nullptr) newroot = cur;      //新指针newroot作记录 cur刚开始为最小的节点 
    pre -> right = cur;                         //当前节点给pre的右子节点
    cur -> left = nullptr;                      //pre左子节点为空
    pre = cur;                                 //pre节点下移

    inorder(cur -> right);
  }
};

int main() {

  return 0;
}