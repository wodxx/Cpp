#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
  vector<vector<int> > Print(TreeNode* pRoot) {
    vector<vector<int>> result;
    queue<TreeNode* > que;
    if (pRoot == nullptr) return result;
    que.push(pRoot);
    bool even = false;
    while (!que.empty()) {
      vector<int> temp;
      int len = que.size();
      for (int i = 0; i < len; i++) {
        TreeNode* cur = que.front();
        if (cur -> left) que.push(cur -> left);
        if (cur -> right) que.push(cur -> right);
        temp.push_back(cur -> val);
        que.pop();
      }
      if (even) {
        reverse(temp.begin(), temp.end());  // 奇数翻转temp数组，推入大数组
        result.push_back(temp);
      } else {
        result.push_back(temp);
      }
      even = !even;                         // 奇数标志值取反
    }
    return result;
  }
};

int main () {

  return 0;
}

