#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:

    int count = 0;    //计数，反向二叉树的最大的一个值
    int result;
    int kthLargest(TreeNode* root, int k) {
        midSort(root,k);
        return result;
    }
    void midSort(TreeNode* root, int k){
        if (root == NULL) return ;
        //先遍历右字树右节点，最后一个是最大值
        midSort(root -> right,k);
        //得到最大值时，计数count++，意为第一大数
        count++;
        if (count == k) {
            result = root -> val;
            return;
        }
        midSort(root -> left,k);
    }
};

int main(){

    return 0;
}