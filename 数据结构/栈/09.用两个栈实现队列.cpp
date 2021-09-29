#include <iostream>
#include <stack>
using namespace std;

class CQueue{
public:
    stack<int> val_stack1;
    stack<int> val_stack2;
    CQueue(){

    }
    //元素值入第一个栈
    void appendTail(int value){
        val_stack1.push(value);
      
    }
    //第一个栈的值入第二个栈
    int deletedHead(){
        if(val_stack2.empty()){
            while(!val_stack1.empty()){
            val_stack2.push(val_stack1.top());
            val_stack1.pop();
            }
        }

        if(val_stack2.empty()){
            return -1;
        //此时第二个栈的元素值正常出栈就和队列的删除顺序是一样的
        } else {
            int result = val_stack2.top();
            val_stack2.pop(); 
            return result;
        }
        //注意：在函数里都是选择语句时，返回值要写在返回语句里，不能
        //写在这里
    }
};

int main(){

    return 0;
}