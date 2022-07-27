#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// 重新生成链表的方法： 如何定义一个新链表
class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    // 重新生成新链表方法
    int len = lists.size(); 
    if (len == 0) return nullptr;
    vector<int> vec;
    for (int i = 0; i < len; i++) {
      ListNode* list = lists[i];                   // 将每一个链表的值加入数组
      while (list != nullptr) {                    // 这里定义的是一个链表的头结点
        vec.push_back(list -> val);
        list = list -> next;
      }
    }
    sort(vec.begin(), vec.end());
    ListNode* NewHead = new ListNode(vec[0]);     // 如何定义一个新节点
    ListNode* cur = NewHead;                      // 新节点赋初值为数组的首元素
    for (int i = 1; i < vec.size(); i++) {
      cur -> next = new ListNode(vec[i]);         // 数组的元素依次为新链表的节点
      cur = cur -> next;
    }
    return NewHead;
  }
};

// 归并
class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    // 归并排序
    if (lists.size() == 0) return nullptr;
    int len = lists.size();
    return mergeSort(lists, 0, len - 1);
  }
  ListNode* mergeSort(vector<ListNode* >& lists, int slow, int high) {
    if (slow >= high) return lists[slow];               // 指针相遇 选择左指针元素
    int mid = slow + ((high - slow) >> 1);
    ListNode* left = mergeSort(lists, slow, mid);
    ListNode* right = mergeSort(lists, mid + 1, high);
    return merge(left, right);
  }
  ListNode* merge(ListNode* left, ListNode* right) {
    ListNode* NewHead = new ListNode(-1);                // 新头节点
    ListNode* cur = NewHead;
    while (left != nullptr && right != nullptr) {
      if (left -> val <= right -> val) {
        cur -> next = left;
        left = left -> next;
      } else {
        cur -> next = right;
        right = right -> next;
      }
      cur = cur -> next;
    }
    if (left != nullptr) cur -> next = left;
    if (right != nullptr) cur -> next = right;
    return NewHead -> next;
  }
};

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) {
      if (head1 == nullptr) return head2;
      if (head2 == nullptr) return head1;
      stack<ListNode* > st1;
      stack<ListNode* > st2;
      while (head1 != nullptr)           // 这里直接移动头结点
        st1.push(head1);
        head1 = head1 -> next;
      while (head2 != nullptr)
        st2.push(head2);
        head2 = head2 -> next;
      int subsum = 0;                     // 进位值初始为0
      while (!st1.empty() || !st2.empty()) {
        int sum = subsum;                 // 两节点的加和(提前包括了前低位的进位值)
        if (!st1.empty()) {
          sum += st1.top() -> val;
          head1 = st1.top();
          st1.pop();
        }
        if (!st2.empty()) {
          sum += st2.top() -> val;        // 从最长的低位开始
          if (st2.size() > st1.size()) {
            head1 = st2.top();
          }
          st2.pop();
        }
        if (sum < 10) {                   // 判断和是否大于10
          head1 -> val = sum;
          subsum = 0;
        } else {
          head1 -> val = sum % 10;
          subsum = sum / 10;
        }
      }
      if (subsum > 0) {                   // 重新定义head2，实质为head1的前一节点
        head2 = new ListNode(subsum);
        head2 -> next = head1;
        return head2;
      } 
      return head1;
    }
};

int main () {

  return 0;
}
