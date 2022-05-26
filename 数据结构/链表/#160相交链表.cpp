#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
  struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lengthA = getlength(headA);
    int lengthB = getlength(headB);
    int dislength = abs(lengthA - lengthB);  //两链表个数差
    ListNode* longlist = headA;            //定义长短链表
    ListNode* shortlist = headB;
    if (lengthB > lengthA) {
      longlist = headB;
      shortlist = headA;
    }
    //(lengthA > lengthB) ? longlist = headA, shortlist = headB : 
    //longlist = headB, shortlist = headA;    //这种双目写法有问题
    for (int i = 0; i < dislength; i++) {
      longlist = longlist -> next;           //长链先遍历两链个数差的步数
    } 
    while ((longlist != nullptr) && (shortlist != nullptr) && (longlist != shortlist)) {
      longlist = longlist -> next;
      shortlist = shortlist -> next;        //同时遍历，两链的节点相等时终止返回
    }
    //ListNode* resultsNode = longlist;
    return longlist;
  }
  int getlength (ListNode* pNode) {         //计算两链表的节点个数
    if (pNode == nullptr) return 0;
    int count = 0;
    while (pNode != nullptr) {
      count++;
      pNode = pNode -> next;
    }
    return count;
  }
};

int main () {

  return 0;
}
