#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

//递归解法
TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
    //递归出口：返回的节点是p或q，此时向上返回此节点；
    if(root == NULL) return NULL;
    if((root == p) || (root == q)) return root;

    //递归左右子树
    TreeNode* lTree = lca(root -> left, p, q);
    TreeNode* rTree = lca(root -> right, p, q);

    if(lTree && rTree) return root;
    else if((lTree == NULL) && (rTree)) return rTree;
    else if((lTree) && (rTree == NULL)) return lTree;
    else return NULL;

    return NULL;
}
int main(){
    return 0;
}
