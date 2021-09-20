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
        return result;
    }
    int depth(TreeNode* root){
        if (root == NULL) return 0;
        int l = 1 + depth(root -> left);
        int r = 1 + depth(root -> right);
        if (abs(l - r) > 1) result = false;
        return max(l,r);
    }
};

int main(){
    return 0;
}