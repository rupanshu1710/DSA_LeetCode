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
    ListNode* reverseList(ListNode* l1) {
        if(l1==NULL)return l1;
        if(l1->next==NULL)return l1;
        ListNode* res = reverseList(l1->next);
        l1->next->next = l1;
        l1->next = NULL;
        return res;
    }
        
};