#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

//用stack，回文前后顺序相同，则可以把链表加入栈再从栈顶与原表对比
class Solution {
public:
  bool isPalindrome(ListNode* head) {
    stack<int> st;                         // 栈里要push的是链表节点的value，不是一个节点
    ListNode* pNode = head;
    while (pNode != nullptr) {
      st.push(pNode -> val);
      pNode = pNode -> next;
    }
    while (head != nullptr) {               //先放到栈里
      if (st.top() != head -> val) {       //顺遍历和栈从顶部开始遍历一样则为回文链表
        return false;
      } else {
        st.pop();
        head = head -> next;
      }
    }
    return true;
  }
};

//回文特性解法：数组长度为n，回文前后对应，则索引i处元素应该等于n-i-1处的元素
class Solution {
public:
  bool isPalindrome(ListNode* head) {
    vector<int> vec;
    ListNode* pNode = head;
    while (pNode != nullptr) {
      vec.push_back(pNode -> val);
      pNode = pNode ->next;
    }
    for (int i = 0; i < vec.size(); i++) {
      if (vec[i] != vec[vec.size() - i - 1]) return false;
      //数组长度为n， 回文前后对应，则索引i处元素应该等于n-i-1处的元素
    }
    return true;
  }
};

int main () {

  return 0;
}