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
  unordered_map<TreeNode*, int> m;          //记忆化递归 去重
public:
  int rob(TreeNode* root) {
    TreeNode* cur = root;
    if (root == nullptr) return 0;           //节点为空，返回0
    if (cur -> left == nullptr && cur -> right == nullptr) return cur -> val;   //递归终止条件
    if (m.count(cur)) return m[cur];        //查找该节点是否被计算过 计算过 返回哈希值
    int val1 = cur -> val;                   //定义一个变量作为当前节点的val
    if (cur -> left) val1 += rob(cur -> left -> left) + rob(cur -> left -> right);
    if (cur -> right) val1 += rob(cur -> right -> left) + rob(cur -> right -> right);
    int val2 = rob(cur -> left) + rob(cur -> right);
    m[cur] = max(val1, val2);                         //记录该节点的val
    return max(val1, val2);  
  }
};

int main () {

  return 0;
}