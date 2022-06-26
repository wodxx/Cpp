#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
};

class Solution {
private:
  vector<string> results;
  string str;
public:
  vector<string> binaryTreePaths(TreeNode* root) {
    if (root == nullptr) return results;
    dfs(root, "");
    return results;
  }
  void dfs(TreeNode* cur, string str) {
    if (cur == nullptr) return;
    str += to_string(cur -> val);
    if (cur -> left == nullptr && cur -> right == nullptr) {
      results.push_back(str);
      return;                     //将字符串str清空
    }
    if (cur -> left) dfs(cur -> left, str + "->");
    if (cur -> right) dfs(cur -> right, str + "->");
  }
};

int main () {

  return 0;
}