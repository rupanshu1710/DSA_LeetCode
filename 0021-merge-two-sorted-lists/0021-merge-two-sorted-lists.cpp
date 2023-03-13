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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        if(!p1)return p2;
        if(!p2)return p1;
        if(p1->val<p2->val){
            while(p1->next && p2){
                if(p1->next->val>p2->val){
                    ListNode* temp1 = p1->next;
                    ListNode* temp2 = p2->next;
                    p1->next = p2;
                    p2->next = temp1;
                    p1 = p2;
                    p2 = temp2;
                }
                else{
                    p1 = p1->next;
                    // p2 = p2->next;
                }
            }
            if(p2)p1->next = p2;
            return list1;
        }
        else{
            p1 = list2;
            p2 = list1;
            while(p1->next && p2){
                if(p1->next->val>p2->val){
                    ListNode* temp1 = p1->next;
                    ListNode* temp2 = p2->next;
                    p1->next = p2;
                    p2->next = temp1;
                    p1 = p2;
                    p2 = temp2;
                }
                else{
                    p1 = p1->next;
                    // p2 = p2->next;
                }
            }
            if(p2)p1->next = p2;
            return list2;
        }
    }
};