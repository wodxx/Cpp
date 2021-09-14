#include <iostream>
using namespace std;

struct ListNode{
    ListNode * next;
    int val;
};
ListNode * FindKthTOTail(ListNode * head,unsigned int k){
    //k的值是否为0
    if (head -> next == NULL || k == 0) return ;
    ListNode * pFast = head;
    ListNode * pSlow = head;
    for (int i = 1; i <= k - 1; ++i){
        //每次循环加一个k大小和此时链表节点数的判断
        if(pFast -> next != NULL){
            pFast = pFast -> next;
        } else {
            return NULL;
        } 
    }
    while (pFast == NULL){
        pFast = pFast -> next;
        pSlow = pSlow -> next;
    }
    return pSlow;
}
int main(){

    return 0;
}