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
private:
  int sum = INT_MIN;
public:
  int maxPathSum(TreeNode* root) {
    if (root == nullptr) return 0;
    dfs(root);
    return sum;
  }
  int dfs(TreeNode* cur) {
    if (cur == nullptr) return;
    int l = max(dfs(cur -> left), 0);  //与0比较 负数不选择
    int r = max(dfs(cur -> right), 0);
    sum = cur -> val + l + r;          //一个节点的最大路径和，可以过节点
    //sum = max(sum, cur -> val + l + r); //也可以写作与已计算过的最大值作比较
    return cur -> val + max(l, r);     //返回 该节点的值与两子节点的最大值之和 即单边最大分支 给该节点的父节点计算使用
  }
};

int main () {

  return 0;
}