// 描述
// 给出一个升序排序的链表，删除链表中的所有重复出现的元素，只保留原链表中只出现一次的元素。
// 要求：空间复杂度 O(n)，时间复杂度 O(n)
// 进阶：空间复杂度 O(1)，时间复杂度 O(n)

// 示例1
// 输入：{1,2,2}
// 返回值：{1}

#include <bits/stdc++.h>
using namespace std;


// 空间复杂度为O(n)解法

struct ListNode {
int val;
struct ListNode *next;
};
class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        if (head == nullptr) return nullptr;
        ListNode* pre = new ListNode(-1);
        pre -> next = head;
        ListNode* cur = pre;  
        // 本题中移动指针不能指向head，如果指向head，当head的next与head值相等时，便无法删掉head
        // 因此cur必须从pre开始，对head作为他的next节点，开始比较删重！！！！！！！！！！！！
        while (cur -> next && cur -> next -> next) {
            if (cur -> next -> val == cur -> next -> next -> val) {   // 当两相邻节点值相等时，继续比较，直到返回不相等的节点
                int temp = cur -> next -> val;
                while (cur -> next && cur -> next -> val == temp) {
                    cur -> next = cur -> next -> next;
                }
            } else {
                cur = cur -> next;
            }
        }
        return pre -> next;
        delete pre;
    }
};


// 空间复杂度为O(1)的解法：递归

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

//没有新建节点，只是调整节点
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) 
    {
        if (!head || !head->next)
            return head;
        if (head->val != head->next->val)
        {
            head->next = deleteDuplicates(head->next); // 不重复时递归传入当前节点的next节点
            return head;
        }
        else
        {
            int tmp = head->val;
            while (head->val==tmp)
            {
                head = head->next;
                if (!head)
                    return NULL;
            }
            return deleteDuplicates(head);        // 在遇到重复节点时递归传入的参数不同
        }
    }
};


int main () {
  return 0;
}