// 请实现两个函数，分别用来序列化和反序列化二叉树。

// 你需要设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 
// 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

// 提示：输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式
// 你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

// 输入：root = [1,2,3,null,null,4,5]
// 输出：[1,2,3,null,null,4,5]

#include <bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    string ans;
    vector<string>nums;//关键，处理-1，255等这样的非单个数字。
    void dfs1(TreeNode*root){
        if(root==NULL){
            ans+='#';
            nums.emplace_back("#");
            return ;
        }
        ans+=to_string(root->val);
        nums.emplace_back(to_string(root->val));
        dfs1(root->left);
        dfs1(root->right);
    }
    string serialize(TreeNode* root) {
        if(root==NULL)return "";
        dfs1(root);
        return ans;
    }


    int idx=0;
   TreeNode* dfs2(TreeNode*root){
       if(nums[idx]=="#"){
           idx++;//这点也很关键，因为只要if语句执行不管该字符串是什么idx就会++。
           return NULL;
       }
       root=new TreeNode(stoi(nums[idx++]));
       root->left=dfs2(root->left);
       root->right=dfs2(root->right);
       return root;

   }
    TreeNode* deserialize(string data) {
        if(data=="")return NULL;
        return dfs2(new TreeNode());
    }
};

int main () {

  return 0;
}
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
