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
  TreeNode* pre = nullptr;
  int results = INT_MAX;
public:
  int getMinimumDifference(TreeNode* root) {
    Caldis(root);
    return results;
  }
  void Caldis(TreeNode* cur) {
    if (cur == nullptr) return;
    Caldis(cur -> left);
    if (pre != nullptr) {       //有前项节点时计算差值       
      results = min(results, abs(cur -> val - pre -> val));
    }
    pre = cur;
    Caldis(cur -> right);
  }
};

int main () {

  return 0;
}