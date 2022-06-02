#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(0);
    ListNode* pNode = head;
    int carry = 0;                                              //进位值
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
      int vall1 = l1 != nullptr ? l1 -> val : 0;                //两表同位置相加
      int vall2 = l2 != nullptr ? l2 -> val : 0;
      int sum = vall1 + vall2 + carry;
      carry = sum / 10;
      ListNode* cur = new ListNode(sum % 10);                  //新表（动态表）节点为和取余的值
      pNode -> next = cur;                                     //把新表第一个节点赋值给原表的指针的后继
      pNode = cur;                                             //原表的的指针等待下一个cur
      if (l1 != nullptr) l1 = l1 -> next;
      if (l2 != nullptr) l2 = l2 -> next;
    }
    return head -> next;
  }
};

int main () {

  return 0;
}