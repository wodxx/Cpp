//给一个数组作为入栈顺序，判断另一个数组是否能称为出栈顺序

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        //给出一个辅助栈，逐步压入入栈顺序数组中的元素
        stack<int> temp_stack;
        int nums = 0;
        //定义nums记录压入辅助栈的元素个数
        //当压入顺序数组中的元素已经为空时，另一个数组还有元素则为false，否则为true
        //对弹出数组的元素逐个遍历
        for (int i = 0; i < popped.size(); i++){       
            if(temp_stack.empty()){
                if(pushed.size() == nums) return false;
                temp_stack.push(pushed[nums]);
                nums++;
            }
            while(temp_stack.top() != popped[i]){
            //辅助栈的栈顶元素与此时遍历的弹出数组的元素相同时则弹出辅助栈栈顶元素
                if(pushed.size() == nums) return false;
                temp_stack.push(pushed[nums]);
                nums++;
            }
            temp_stack.pop();
        }
        return true;
    }
};

int main(){
    return 0;
}