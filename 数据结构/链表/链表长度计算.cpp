//用来计算链表长度（节点个数）的函数，用于需要链表个数的程序中
#include <iostream>
using namespace std;

//先定义一个节点结构体，有 next指针和节点的值 这两个成员变量！
struct ListNode{
        ListNode * next;
        int val;
};
//计算链表节点长度的函数
unsigned int GetLength(ListNode * head){
    ListNode * pNode = head;
    unsigned int length = 0;
    while (pNode != NULL){
        ++length;
        pNode = pNode -> next;
    }
    return length;
}

int main(){
     //给实参调用GetLength()函数计算链表的长度！
     return 0; 
}

