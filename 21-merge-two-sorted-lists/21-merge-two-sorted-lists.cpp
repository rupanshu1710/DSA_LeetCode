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
        if(!list1)return list2;
        if(!list2)return list1;
        ListNode* p1;
        ListNode* p2;
        ListNode* t1;
        ListNode* t2;
        ListNode* ans;
        if(list1->val<=list2->val)
        {
            p1 = list1;
            ans = list1;
            p2 = list2;
            while(p1->next && p2)
            {
                if(p1->next->val>p2->val)
                {
                    t1 = p1->next;
                    t2 = p2->next;
                    p1->next = p2;
                    p2->next = t1;
                    p1 = p2;
                    p2 = t2;
                }
                else 
                {
                    p1 = p1->next;
                }
            }
            if(!p1->next)p1->next = p2;
        }
        else
        {
            p1 = list2;
            p2 = list1;
            ans = list2;
            while(p1->next && p2)
            {
                if(p1->next->val>p2->val)
                {
                    t1 = p1->next;
                    t2 = p2->next;
                    p1->next = p2;
                    p2->next = t1;
                    p1 = p2;
                    p2 = t2;
                }
                else 
                {
                    p1 = p1->next;
                }
            }
            if(!p1->next)p1->next = p2;
        }
        return ans;
        
    }
};