#include <iostream>
using namespace std;

struct ListNode{
    ListNode * next;
    int val;
};

//给出一个链表的头节点和一个要删除的指针节点
void ListNodeDelete(ListNode * head,ListNode * pDeleted){
    if (head == NULL || pDeleted == NULL) return ;
    //要删除的节点不是尾节点
    if (pDeleted -> next != NULL){
        ListNode * pNode1 = pDeleted -> next;
        pDeleted -> val = pNode1 -> val;
        pDeleted -> next = pNode1 -> next;
        delete pNode1;
        pNode1 =  NULL;
    //链表只有一个节点
    } else if (head -> next == NULL){
        delete pDeleted;
        head == NULL;
        pDeleted == NULL;
    //链表有其他节点，删除尾节点    
    } else {
        ListNode * pNode2 = head;
        while (pNode2 -> next != pDeleted){
            pNode2 = pNode2 -> next;
        }
        pNode2 -> next == NULL;
        delete pDeleted;
        pDeleted == NULL;
    }
}
int main(){
    
    return 0;
}