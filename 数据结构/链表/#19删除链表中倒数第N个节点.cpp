#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr) return nullptr;
    ListNode* pNode = head;
    ListNode* pFast = head;
    ListNode* pSlow = head;
    for (int i = 0; i < n; i++) {                //快指针先走n步
      pFast = pFast -> next;
    }
    if (pFast == nullptr) return pNode -> next;  //没有n个节点，从pNode -> next 返回
    while (pFast -> next != nullptr) {
      pFast = pFast -> next;
      pSlow = pSlow -> next;                     //两指针一起走
    }                                            //快指针走到末尾，此时慢指针刚好指向要被删除的指针的前驱指针处
    pSlow -> next = pSlow -> next -> next;
    return pNode;
  }
};

int main () {
  
  return 0;
}
