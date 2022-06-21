#include <iostream>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

//从二叉树的层序遍历（32题）想到的方法:逐层计数法！
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> que;
        int count = 0;
        if (root == NULL) return count;
        que.push(root); 
        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i < size; i++){                     //开启一个循环pop完栈的元素
                TreeNode* pNode = que.front();
                que.pop();
                if (pNode -> left) que.push(pNode -> left); 
                if (pNode -> right) que.push(pNode -> right);
            }count++;
            //每一层循环完后计数值加一
        }
        return count;
    }   
};


/*********************************

[递归]

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int l = maxDepth(root -> left);
        int r = maxDepth(root -> right);
        return max(l,r) + 1;
        //return (l > r) ? （l : r) + 1
    }
};

[原理]
一颗二叉树的深度是它根节点的左子树和右子树的深度的最大者再加1得到！

***********************************/


int main(){
     
     return 0;
}