#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* pNode = root;

        //利用前序和中序找跟节点的位置
        int index = 0;
        for(int i = 0; i < inorder.size(); ++i){
            if(preorder[0] == inorder[i]){
                index = i;
                break;
            }
        }

        //定义四个数组，分别遍历左右字树的前中序
        vector<int> leftpreorder, rightpreorder,leftinorder,rightinorder;
        for(int i = 1; i <=index; ++i) leftpreorder.push_back(preorder[i]);
        for(int i = index + 1; i < preorder.size(); ++i) rightpreorder.push_back(preorder[i]);
        for(int i = 0; i < index; ++i) leftinorder.push_back(inorder[i]);
        for(int i = index + 1; i < inorder.size(); ++i) rightinorder.push_back(inorder[i]);

        //對左右字树进行递归
        pNode -> left = buildTree(leftpreorder,leftinorder);
        pNode -> right = buildTree(rightpreorder,rightinorder);

        return root;
    }
};

int main(){
    return 0;
}


/******************************************************************************************
知识点：

前序遍历列表：第一个元素永远是 【根节点 (root)】
中序遍历列表：根节点 (root)【左边】的所有元素都在根节点的【左分支】，【右边】的所有元素都在根节点的【右分支】

(由此规律可以在前序遍历中找到跟节点，在中序遍历中跟节点左边的就是左分支，右边的就是右分支。并且左右分支的个数在中序遍历中已知后
在前序遍历中可以知道那些元素时左分支的，那些是右分支的。这对于做选择题中的已知两种遍历求另一种遍历很重要！同理，如果已知后序和中序
求前序遍历，则后序最后一个为根元素，同样从后序遍历中数出左右分支的个数来帮助写出前序遍历！！！！！！！！！)


算法思路：

通过【前序遍历列表】确定【根节点 (root)】
将【中序遍历列表】的节点分割成【左分支节点】和【右分支节点】
递归寻找【左分支节点】中的【根节点 (left child)】和 【右分支节点】中的【根节点 (right child)】
最后会找出每一个节点（按层序遍历的顺序）。
重建二叉树就是用分治的思想遍历找根节点，即每一个节点都会被遍历。

******************************************************************************************/

// 2022 6.10

class Solution {
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() == 0) return nullptr;   //前序首元素为根节点
    TreeNode* root = new TreeNode(preorder[0]);
    TreeNode* cur = root;
    int index = 0;
    for (int i = 0; i < inorder.size(); ++i) {    //在中序里根据根节点分左右子树
      if (preorder[0] == inorder[i]) {
        index = i;                            //注意这里！这里是将i赋值给index，不是index == i
        break;
      }
    }
    //左右子树的前中序递归
    vector<int> leftpreorder, rightpreorder, leftinorder,  rightinorder;
    for (int i = 1; i <= index; ++i) leftpreorder.push_back(preorder[i]); //前序从1开始，绕过根节点
    for (int i = index + 1; i < preorder.size(); ++i) rightpreorder.push_back(preorder[i]);
    for (int i = 0; i < index; ++i) leftinorder.push_back(inorder[i]);
    for (int i = index + 1; i < inorder.size(); ++i) rightinorder.push_back(inorder[i]);
    cur -> left = buildTree(leftpreorder, leftinorder);
    cur -> right = buildTree(rightpreorder, rightinorder);
    return root;
  }
};