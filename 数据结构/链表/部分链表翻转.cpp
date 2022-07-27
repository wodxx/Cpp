// 描述
// 将给出的链表中的节点每 k 个一组翻转，返回翻转后的链表
// 如果链表中的节点数不是 k 的倍数，将最后剩下的节点保持原样
// 你不能更改节点中的值，只能更改节点本身。

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
  ListNode* reverseKGroup(ListNode* head, int k) {                                             
    if (head == nullptr) return nullptr;                 // 先找到第k个节点，从head到第k个翻转
    ListNode* node = head;
    for (int i = 0; i < k; i++) {
      if (node == nullptr) return head;                  // 不够k个，则从head开始
      node = node -> next;
    }
    ListNode* NewHead = reverseNode(head, node);         // 新链表的头结点
    head -> next = reverseKGroup(node, k);               // 继续从node开始寻找下一个第k个节点 
    return NewHead;                                      // 为什么是head -> next? 因为下一个第k个节点翻转过来就是head的next节点
  }
  ListNode* reverseNode (ListNode* head, ListNode* last) {
    ListNode* pre = nullptr;
    while (head != last) {                               // 这个函数结束，head节点和第k个节点重合
      ListNode* temp = head -> next;
      head -> next = pre;
      pre = head;
      head = temp;
    }
    return pre;
  }
};

int main () {

  return 0;
}
