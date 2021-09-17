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
    vector< vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> >result;
        queue<TreeNode*>que;              //注意：这里队列的数据类型为指针
        if (root == NULL) return result;
        que.push(root);
        while (!que.empty()){
            vector<int> vec;
            int size = que.size();                    //这里for循环是将一层的元素值放入数组里
            for (int i = 0; i < size; i++){           //这里i的范围不能直接小于que.size（），因为的队列的长度在变（下面新加入队列的子节点）
                TreeNode* pNode = que.front();        //必须时树的一层里的元素值都入小数组（vec)后，再开启下一个while循环
                que.pop();                            //因为是一层的值在一个小数组，所以每一个入队的元素先出队再入小数组。
                if(pNode -> left ) que.push(pNode -> left );
                if(pNode -> right) que.push(pNode -> right );
                vec.push_back(pNode -> val);
            }
            result.push_back(vec);                   //一个for循环完后，将一个小数组推进大数组
        }
        return result;
    }
};

int main(){

    return 0;
}