#include <bits/stdc++.h>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr) return nullptr;
    ListNode* pNode = head;
    ListNode* reNode = nullptr;
    ListNode* pPre = nullptr;
    while (pNode != nullptr) {
      ListNode* pNext = pNode -> next;
      if (pNext == nullptr) reNode = pNode;
      pNode -> next = pPre;
      pPre = pNode;
      pNode = pNext;
    }
    return reNode;
  }
};

int main () {

  return 0;
}


