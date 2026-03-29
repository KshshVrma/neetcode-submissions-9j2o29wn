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
ListNode* mergeList(ListNode* l1, ListNode* l2){
    if(l1==NULL)return l2;
    if(l2==NULL)return l1;
    if(l1->val<=l2->val){
        l1->next=mergeList(l1->next, l2);
        return l1;

    }else{
        l2->next=mergeList(l1, l2->next);
       return l2;
    }

}

ListNode* partition(vector<ListNode*>& lists, int start, int end){
    if(start>end)return NULL;
    if(start==end){
        return lists[start];
    }
    int mid=start+(end-start)/2;
    ListNode* l1=partition(lists, start, mid);
    ListNode*l2 =partition(lists, mid+1, end);
    return mergeList(l1, l2);
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        return partition(lists, 0, lists.size()-1);
    }
};
