#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* removeElements(ListNode* head, int val) {
    if (head == nullptr) return head;
    ListNode* dummyhead = new ListNode(0);
    dummyhead -> next = head;                 //定义一个虚拟节点作为头节点的前驱节点
    ListNode* pNode = dummyhead;      
    while (pNode -> next != nullptr) {
      if (pNode -> next -> val == val) {      //用移动节点的后继节点的值来与val比较
        pNode -> next = pNode -> next -> next;   //删除操作 
      } else {
        pNode = pNode -> next;
      }
    }
    return dummyhead -> next;
    delete dummyhead;              //释放内存
  }
};

int main () {

  return 0;
}