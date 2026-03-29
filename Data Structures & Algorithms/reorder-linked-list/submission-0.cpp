/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
ListNode* reverse(ListNode* head){
    ListNode* prev=NULL;
    ListNode* currNext=NULL;
    ListNode* curr=head;
    while(curr!= NULL){
        currNext=curr->next;
        curr->next=prev;
        prev=curr;
        curr=currNext;
    }
    return prev;
}
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL)return ;
        ListNode*slow=head;ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* rev=reverse(slow);

        ListNode* front=head;
        ListNode* frontnext=NULL;
        ListNode* revnext=NULL;
        while(rev->next!=NULL){
            revnext=rev->next;
            frontnext=front->next;
front->next=rev;
rev->next=frontnext;
front=frontnext;
rev=revnext;

        }
    }
};
