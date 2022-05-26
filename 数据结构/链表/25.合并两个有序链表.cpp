//比大小，然后递归

#include <iostream>
using namespace std;

struct ListNode{
    ListNode * next;
    int val;
};

ListNode * MergeList(ListNode * head1,ListNode * head2){
    if (head1 == NULL) {
        return head2;
    } else if (head2 == NULL){
        return head1;
    }
    ListNode * MergeHeadNode = NULL;
    if (head1 -> val < head2 -> val){
        MergeHeadNode = head1;
        MergeHeadNode -> next = MergeList(head1 -> next,head2);
    } else {
        MergeHeadNode = head2;
        MergeHeadNode -> next = MergeList(head1,head2 -> next);
    }
    return MergeHeadNode;
}
int main(){

    return 0;
}