#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// 输入：
// [9,3,7],[6,3]
// 返回值：
// {1,0,0,0}

class Solution {
public:
    /**
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here
        if(head1 == NULL)
        {
            return head2;
        }
        if(head2 == NULL)
        {
            return head1;
        }
        
        stack<ListNode *> s1;
        stack<ListNode *> s2;
        while(head1 != NULL)
        {
            s1.push(head1);
            head1 = head1->next;
        }
        while(head2 != NULL)
        {
            s2.push(head2);
            head2 = head2->next;
        }
        int subsum = 0;
        while(!s1.empty()||!s2.empty())
        {
            int sum = subsum;
            if(!s1.empty())                       // 栈1栈顶元素要出栈
            {
                sum += s1.top()->val;
                head1 = s1.top();
                s1.pop();
            }
            if(!s2.empty())
            {
                sum += s2.top()->val;
                if(s2.size()>s1.size())
                {
                    head1 = s2.top();            // 指针在长低位
                }                                // 如果S2的size大于S1，则一直在改变S2的节点的大小
                s2.pop();
            }
            if(sum < 10)
            {
                subsum = 0;
                head1->val = sum;
            }
            else
            {
                subsum = sum/10;
                head1->val = sum%10;
            }
        }
        if(subsum > 0)
        {
            head2 = new ListNode(subsum);
            head2->next = head1;
            return head2;
        }
        
        return head1;
    }
};

int main () {

  return 0;
}