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
     ListNode* reverse(ListNode* l1) {
        if(l1==NULL)return l1;
        if(l1->next==NULL)return l1;
        ListNode* res = reverse(l1->next);
        l1->next->next = l1;
        l1->next = NULL;
        return res;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;
        ListNode* curr2 = head;
        while(curr2 && curr2->next){
            curr = curr->next;
            curr2 = curr2->next->next;
        }
        ListNode* head2 = reverse(curr);
        ListNode* head1 = head;
        int a = 0;
        while(head2){
            if(head1->val!=head2->val)return 0;
            head1 = head1->next;
            head2 = head2->next;
        }
        return 1;
    }
};