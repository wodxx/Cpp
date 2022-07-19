#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    ListNode * next;
    int val;

  ListNode* removeNthFromEnd(ListNode* head, int n) {
     // 删除节点的题目 要new一个新的头结点来进行操作
    ListNode* resultList = nullptr;
    resultList -> next = head;
    ListNode* pre = resultList;    //pre是新头结点的移动指针，fast和slow是原头结点的移动指针
    ListNode* fast = head;
    ListNode* slow = head;
    while (n--) {                   //快慢指针找到倒数第n个节点
      fast = fast -> next;
    }
    while (fast != nullptr) {
      fast = fast -> next;
      pre = slow;
      slow = slow -> next;         //pre指向倒数第n个节点的前一个节点
    }
    pre -> next = slow -> next;
    return resultList -> next;
    delete resultList;
  }
};

int main () {

  return 0;
}

