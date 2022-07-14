#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* sortInList(ListNode* head) {
    if (head == nullptr) return nullptr;
    ListNode* cur = head;
    vector<int> vec;
    while (cur != nullptr) {
      vec.push_back(cur -> val);
      cur = cur -> next;
    }
    cur = head;  // cur再次指向head节点
    sort(vec.begin(), vec.end());
    for (auto c : vec) {         //将这个链表的每个节点的值重新变换
      cur -> val = c;
      cur = cur -> next;
    }
    return head;
  }
};