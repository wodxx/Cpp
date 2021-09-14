#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct ListNode{
    ListNode * next;
    int val;
};

vector<int>ReversePrint (ListNode * head){
    if (head -> next == NULL) return ;
    stack<int>results;
    vector<int>nodes;
    ListNode * pNode = head;

    while (pNode == NULL){
        results.push(pNode -> val);
        pNode = pNode -> next;
    }
    
    while (!results.empty()){
        nodes.push_back(results.top());
        results.pop();
    }
    return nodes;
}
//先入栈再入组最后返回

int main(){

    return 0;
}