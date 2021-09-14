#include <iostream>
using namespace std;

struct ListNode{
    ListNode * next;
    int val;
};

//已知两个头节点的链表
ListNode * FirstCommonNode(ListNode * headA,ListNode * headB){
    unsigned int length1 = GetLength(headA);
    unsigned int length2 = GetLength(headB);
    unsigned int lengthdiss = length1 - length2;
    ListNode * pLong = headA;
    ListNode * pShort = headB;
    if (length2 > length1){
         pLong = headB;
        pShort = headA;
        lengthdiss = length2 - length1;
    }
    for (int i = 0; i < lengthdiss; ++i){
        pLong = pLong -> next;
    }
    //注意循环截至条件
    while (pLong != NULL && pShort != NULL && pLong != pShort){
        pLong = pLong -> next;
        pShort = pShort -> next;
    }
    ListNode * SameNode = pLong;
    return SameNode;
}

unsigned int GetLength(ListNode * head){
    unsigned int length = 0;
    ListNode * pNode = head;
    while (pNode != NULL){
        ++length;
        pNode = pNode -> next; 
    }
    return length;
}

int main(){
    ListNode * FirstCommonNode();
    return 0;
}