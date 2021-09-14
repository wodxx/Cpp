#include <iostream>
using namespace std;

int main(){

    struct TreeNode {
        int val;
        TreeNode * left;
        TreeNode * right;
    };
    
    class Solution{
    public:
        bool isSymetric(TreeNode * root){
            if (root == NULL) {
                return true;
            } else {
                return JudgeTree(root -> left,root -> right);
            }
        }
        bool JudgeTree(TreeNode * left,TreeNode * right){
            if (left == NULL && right == NULL){
                //直到左右两子节点为空时则返回true
                return true;
            } else if(left == NULL || right == NULL){
                return false;
            } else if(left -> val != right -> val){
                return false;
            } else {
                //按‘左左右右和左右右左’一直遍历下去，能在末端节点处为空则返回true
                return JudgeTree(left -> left ,right -> right) &&
                JudgeTree(left -> right,right -> left);
            }
        }
    };
    
    return 0;
}
    


