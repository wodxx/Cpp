#include <iostream> 
using namespace std;

int main(){
    struct TreeNode {
        int val;
        TreeNode * left;
        TreeNode * right;
        void swap();
    };

//前序递归法
/*********************************************
    class Solution {
    public:
        TreeNode * mirrorTree(TreeNode * root){
            if (root == NULL) return NULL;
            swap (root -> left,root -> right);
            mirrorTree(root -> left);
            mirrorTree(root -> right);
            return root;
        }
    };
********************************************/

//临时指针交换法
    class Solution {
    public:
        TreeNode * mirrorTree(TreeNode * root){
            if (root == NULL){
                return 0;
            } else {
                TreeNode * temp = root -> left;
                //递归右子节点赋值给左子节点
                root -> left = mirrorTree(root -> right);
                //递归临时节点赋值给右子节点
                root -> right = mirrorTree(temp);
                return root;
            }
        }
    };
    return 0;
}

