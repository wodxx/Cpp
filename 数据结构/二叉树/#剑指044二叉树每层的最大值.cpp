#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res ; 
        if(!root) return res ; 
        queue<TreeNode*> q ; 
        q.push(root) ; 
        while(!q.empty()){
            int Max = q.front() -> val ; 
            for(int i = q.size() ; i ; i --){
                auto node = q.front() ; 
                q.pop() ; 
                if(node -> val > Max) Max = node -> val ; 
                if(node -> left) q.push(node -> left) ; 
                if(node -> right) q.push(node -> right) ; 
            }
            res.push_back(Max) ; 
        }
        return res ; 
    }
};

int main() {

  return 0;
}