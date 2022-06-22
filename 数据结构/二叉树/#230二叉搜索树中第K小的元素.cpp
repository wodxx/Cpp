#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:       
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;                       //左链入栈
        int num=0;                                //利用BST的中序后会排序
        TreeNode *cur=root;
        while(!s.empty() || cur)
        {
            if(cur)
            {
                s.push(cur);
                cur=cur->left;
            }
            else                               //有节点入栈，无节点 栈顶节点出栈
            {                                  //有入无出！！！！！！！！
                cur=s.top();
                s.pop();
                num++;  
                if(num==k)                     //这里num自加到k后可以返回 当前节点值即为第k小值
                    return cur->val;
                cur=cur->right;
            }
        }
        return 0;
    }
};

int main (){

  return 0;
}