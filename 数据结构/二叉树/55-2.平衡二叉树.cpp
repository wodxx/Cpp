#include<iostream> 
#include<cmath>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    bool result = true;   
    bool isBalanced(TreeNode* root) {
        depth(root);
        return result;                                //返回的是一个bool型变量
    }
    int depth(TreeNode* root){                       //要计算深度 这里函数定义为int 
        if (root == NULL) return 0;       
        int l = 1 + depth(root -> left);             //每个节点自带一个高度
        int r = 1 + depth(root -> right);
        if (abs(l - r) > 1) result = false;
        return max(l,r);
    }
};

int main(){
    return 0;
}



 