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
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode* root = nullptr;
    for (int i = 0; i < preorder.size(); i++) {
      buildTree(root, preorder[i]);                //遍历每一个节点 分配其位置
    }
    return root;
  }
  void buildTree(TreeNode* &cur, int val) {        //传入地址
    if (cur == nullptr) {                          //这个节点为空 则给这个节点赋值 并返回递归
      cur = new TreeNode(val);                     //返回后得到下一个值
      return;
    }
    if (cur -> val > val) {                        //比较当前节点的值和下一个节点的值的大小
      buildTree(cur -> left, val);                 //比下一个节点的值大 则下一个节点为左子节点
    } else {                                       //反之为右子节点
      buildTree(cur -> right, val);
    }
  }
};

int main () {

  return 0;
}