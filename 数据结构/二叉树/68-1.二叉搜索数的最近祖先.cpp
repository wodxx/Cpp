#include <iostream>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 搜索二叉树的公共祖先分四种情况
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        //p，q分列根节点两边，返回root
       if((p -> val < root -> val && q -> val > root -> val) ||
       (q -> val < root -> val && p -> val > root -> val))  return root;

        //p和q有一个为跟节点，返回根节点
       if((p -> val == root -> val) || (q -> val == root -> val))return root;

        //p和q在同一遍的情况，继续递归这一边找公共祖先
       if((p -> val < root ->val) && (q -> val < root -> val))
       return lowestCommonAncestor(root -> left, p, q);

       if((p -> val > root ->val) && (q -> val > root -> val))
       return lowestCommonAncestor(root -> right, p, q);

       return NULL;
    }
};

int main(){
    return 0;
}