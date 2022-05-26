#include <bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
  Node* copyRandomList(Node* head) {
    //原地复制各节点
    if (head == nullptr) return nullptr;
    Node* pNode = head;
    while (pNode != nullptr) {
      Node* pCloned = new Node(pNode -> val);    //注意这里new的指针的初始值
      pCloned -> next = pNode -> next;
      pNode -> next = pCloned;
      pNode = pNode -> next -> next;
    }
    //指定每个节点的随即指针
    pNode = head;
    while (pNode != nullptr) {
      if (pNode -> random != nullptr) {
        pNode -> next -> random = pNode -> random -> next;
      }
      pNode = pNode -> next -> next;
    }
    //将现在的链表一分为二
    Node* pCloned = head -> next;
    pNode = head;
    Node* pCur = head -> next;
    while (pNode != nullptr) {
      pNode -> next = pNode -> next -> next;
      pNode = pNode -> next;
      if (pCur -> next != nullptr) {
        pCur -> next = pCur -> next -> next;
        pCur = pCur -> next;
      }
    }
    return pCloned;
  }
};

int main () {

  return 0;
}