#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
vector<vector<int> > results;
vector<int> temp;
public:
  vector<vector<int>> pathSum(TreeNode* root, int target) {
    dfs(root, target);
    return results;
  }
  void dfs(TreeNode* cur, int target) {
    if (cur == nullptr) return;                //dfs终止条件
    temp.push_back(cur -> val);
    target -= cur -> val;
    if (cur -> left == nullptr && cur -> right == nullptr 
    && target == 0) results.push_back(temp);   //到叶子节点且target减到0入大数组  
    dfs(cur -> left, target);                  //递归 这里不判空
    dfs(cur -> right, target);                 //
    temp.pop_back();                          //清空内数组
  }
};