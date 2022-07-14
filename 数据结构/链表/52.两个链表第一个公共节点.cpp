#include <iostream>
using namespace std;

struct ListNode{
    ListNode * next;
    int val;
};

//已知两个头节点的链表  链表长度计算法
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

//循环遍历法： 两链表对于两指针来说加和一样，所以让任一指针先遍历一个链表，遍历完之后
//再遍历另一个链表;另一个指针也是如此，后面两指针相遇，即说明共同指向了两链表的共同节点。
class Solution {
public:
  ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    //if (pHead1 == nullptr || pHead2 == nullptr) return nullptr;
    ListNode* p1 = pHead1;
    ListNode* p2 = pHead2;
    while (p1 != p2) {
      if (p1 != nullptr) p1 = p1 -> next;
      else  p1 = pHead2;
      if (p2 != nullptr) p2 = p2 -> next;
      else p2 = pHead1;
    }
    return p1;
  }
};

//哈希：找是否存在
class Solution {
public:
  ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    if (pHead1 == nullptr || pHead2 == nullptr) return nullptr;
    set<ListNode*> node;
    ListNode* cur1 = pHead1;
    ListNode* cur2 = pHead2;
    while (cur1 != nullptr) {
      node.insert(cur1);
      cur1 = cur1 -> next;
    }
    while (cur2 != nullptr) {
      if (node.count(cur2)) {
        return cur2;
        break;
      } else {
        cur2 = cur2 -> next;
      }
    }
    return 0;
  }
};

int main(){
    ListNode * FirstCommonNode();
    return 0;
}