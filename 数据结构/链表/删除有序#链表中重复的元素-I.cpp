#include <iostream>
using namespace std;

struct ListNode{
    ListNode * next;
    int val;
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      // 链表中的元素从小到大有序
      if (head == nullptr) return nullptr;
      ListNode* cur = head;
      while (cur != nullptr && cur -> next != nullptr) {
        if (cur -> next -> val == cur -> val) {
          // 这一步是删除与cur节点相同的下一节点，让下下一节点补上来，继续判断
          // 故这里不用移动cur
          // 当cur与其next不相同的时候才开始移动cur
          cur -> next = cur -> next -> next;
        } else {
          cur = cur -> next;
        }
      }
      return head;
    }
};

int main () {

  return 0;
}