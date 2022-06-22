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
  unordered_set<int> s;            //一个数组中找两数之和可以用s.count()函数
  bool results = false;
public:
  bool findTarget(TreeNode* root, int k) {
    func(root);
    for (int i : s) {
      if (s.count(k - i) && (k - i) != i) results = true;
      //加上判重语句 k-i != i
    }
    return results;
  }
  void func(TreeNode* cur) {
    if (cur == nullptr) return;
    func(cur -> left);
    s.insert(cur -> val);
    func(cur -> right);
  }
};

int main () {

  return 0;
}