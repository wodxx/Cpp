#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

//递归解法，参数为节点
TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
    //递归出口：返回的节点是p或q，此时向上返回此节点；
    if(root == NULL) return NULL;
    if((root == p) || (root == q)) return root;            //递归左右子树
    TreeNode* lTree = lca(root -> left, p, q);             //定义左右树的节点来接收递归后的结果
    TreeNode* rTree = lca(root -> right, p, q);
    if(lTree && rTree) return root;
    else if((lTree == NULL) && (rTree)) return rTree;
    else if((lTree) && (rTree == NULL)) return lTree;
    else return NULL;
}

// 参数为节点的value
class Solution {
public:
  int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
    if (root == nullptr) return -1;                       // 判空 没有值 的整型函数 返回-1
    if (root -> val == o1 || root -> val == o2) return root -> val; 
    int left = lowestCommonAncestor(root -> left, o1, o2);
    int right = lowestCommonAncestor(root -> right, o1, o2);
    if (left != -1  && right != -1) return root -> val;   // 分列根节点两子树 公共祖先为root
    else if (left == -1) return right;
    else if (right == -1) return left;
    else return -1;
  }
};

int main(){
    return 0;
}
