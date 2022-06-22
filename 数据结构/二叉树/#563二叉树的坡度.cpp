#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
private:
  int results = 0;
public:
  int findTilt(TreeNode* root) {
    calsum(root);
    return results;                   //求每一个节点的坡度后相加
  }
  int calsum(TreeNode* cur) {
    if (cur == nullptr) return 0;
    int l = calsum(cur -> left);
    int r = calsum(cur -> right);
    results += abs(l - r);
    return cur -> val + l + r;   //返回的是每个节点及其子节点值的和
  }
};

int main() {

  return 0;
}