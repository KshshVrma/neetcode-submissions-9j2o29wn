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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //here we can divide the problem into subproblems and let recursion handle the sorting, the point beign that we can compare two heads
        //everytime and then we would get to know that which should be the current head, this process can be repeated till we reach a base case
        //where either both are empty or one of them is empty
        if(list1==NULL && list2==NULL)return NULL;
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        ListNode* head=(list1->val<=list2->val)?list1:list2;
        if(list1->val<=list2->val){
            list1->next=mergeTwoLists(list1->next, list2);
        }else{
            list2->next=mergeTwoLists(list1, list2->next);
        }
       return head;
    
    }
};
