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
    ListNode* doubleIt(ListNode* head) {
        ListNode* head2 =head;
        ListNode* head1 = reverseList(head);
        int carry = 0;
        ListNode* node = head1;
        while(node){
            node->val *= 2;
            node->val += carry;
            carry = node->val/10;
            node->val %= 10; 
            node = node->next;
            // if(node)cout<<node->val<<" "<<carry<<endl;
        }
        if(carry!=0){
            head2->next = new ListNode(1);
        }
        return reverseList(head1);
    }
};