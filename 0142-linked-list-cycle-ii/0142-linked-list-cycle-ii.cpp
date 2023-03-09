/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next){
            return NULL;
        }
        ListNode *fast = head->next->next;
        ListNode *slow= head->next;
        while(fast!=NULL && fast->next!=NULL && fast!=slow)
        {
            
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast==NULL || fast->next==NULL)return NULL;
        fast = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;

    }
};