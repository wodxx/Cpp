#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;

class MinStack {
public:
    //定义两个栈
    stack<int> val_stack;
    stack<int> min_stack;
    /** initialize your data structure here. */
    MinStack() {
        min_stack.push(INT_MAX);    
    }
    void push(int x) {
        //压栈函数，普通栈直接入栈
        val_stack.push(x);
        //维持最小栈的栈顶元素值最小
        if (min_stack.empty() || x <= min_stack.top()){
            min_stack.push(x);
        }
    }
    void pop() {
        //出栈函数
        //最小栈出栈有条件，普通栈直接出栈
        if (val_stack.top() == min_stack.top()){
            min_stack.pop();
        }
        val_stack.pop();
    }
    int top() {
        return val_stack.top();
    }   
    int min() {
        return min_stack.top();
    }
};

int main(){
    return 0;
}