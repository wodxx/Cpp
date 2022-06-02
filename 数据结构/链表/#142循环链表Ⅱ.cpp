#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (head == nullptr) return nullptr;
    ListNode* pFast = head;
    ListNode* pSlow = head;
    while (true) {
      if (pFast -> next == nullptr || pSlow -> next == nullptr) return nullptr;
      pFast = pFast -> next -> next;
      pSlow = pSlow -> next;
      if (pFast == pSlow) break;                //是一个循环链表
    }
    pSlow = head;                               //慢指针从头开始循环
    while (pFast != pSlow) {
      pFast = pFast -> next;                    //两指针再次相遇得到入口节点
      pSlow = pSlow -> next;
    }
    return pSlow;
  }
};

int main() {
  
  return 0;
}