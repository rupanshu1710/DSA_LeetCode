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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* node1 = head;
        ListNode* node2 = head;
        int temp=0;
        while(curr){
            temp += curr->val;
            if(curr->val==0){
                curr->val = temp;
                temp=0;
                node1->next = curr;
                node1 = curr;
            }
            curr = curr->next;
        }
        return node2->next;
    }
};