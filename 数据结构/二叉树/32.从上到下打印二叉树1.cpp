#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
       queue<TreeNode*> que;
       vector<int> result;
       if (root == NULL) return result;
       que.push(root);
       while (!que.empty()){
           for(int i = 0; i < que.size(); i++){
               TreeNode* pNode = que.front();
                que.pop();
                if(pNode -> left) que.push(pNode -> left);
                if(pNode -> right) que.push(pNode -> right);
                result.push_back(pNode -> val);
           }
       }
       return result;
    }
};

int main(){
    
    return 0;
}