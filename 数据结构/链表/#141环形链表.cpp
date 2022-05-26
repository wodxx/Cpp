#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

//两指针
class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr) return false;
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast!= NULL && fast -> next != NULL) {   
      //终止条件是：fast->next != NULL,并且一定要先判断fast!= nullptr!!!!!!!!
      slow = slow -> next;          
      fast = fast -> next -> next;                        //快慢指针这里分歧
      if (fast == slow) {
        return true;
        break;
      }
    }
    return false;
  }
};

//hash
class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr) return false;
    unordered_set<ListNode*> S;
    ListNode* pNode = head;
    while (true) {                //just开启一个循环
      if (pNode == nullptr) {
        return false;
      }
      if (S.count(pNode)) {
        return true;
      } else {
        S.insert(pNode);        //一个问题：有相同的节点出现即表示循环。后面即使出现
        pNode = pNode -> next; //值相等的节点但地址不同，则不为同一个节点，不矛盾。
      }
    }
    return false;
  }
};

int main () {

  return 0;
}