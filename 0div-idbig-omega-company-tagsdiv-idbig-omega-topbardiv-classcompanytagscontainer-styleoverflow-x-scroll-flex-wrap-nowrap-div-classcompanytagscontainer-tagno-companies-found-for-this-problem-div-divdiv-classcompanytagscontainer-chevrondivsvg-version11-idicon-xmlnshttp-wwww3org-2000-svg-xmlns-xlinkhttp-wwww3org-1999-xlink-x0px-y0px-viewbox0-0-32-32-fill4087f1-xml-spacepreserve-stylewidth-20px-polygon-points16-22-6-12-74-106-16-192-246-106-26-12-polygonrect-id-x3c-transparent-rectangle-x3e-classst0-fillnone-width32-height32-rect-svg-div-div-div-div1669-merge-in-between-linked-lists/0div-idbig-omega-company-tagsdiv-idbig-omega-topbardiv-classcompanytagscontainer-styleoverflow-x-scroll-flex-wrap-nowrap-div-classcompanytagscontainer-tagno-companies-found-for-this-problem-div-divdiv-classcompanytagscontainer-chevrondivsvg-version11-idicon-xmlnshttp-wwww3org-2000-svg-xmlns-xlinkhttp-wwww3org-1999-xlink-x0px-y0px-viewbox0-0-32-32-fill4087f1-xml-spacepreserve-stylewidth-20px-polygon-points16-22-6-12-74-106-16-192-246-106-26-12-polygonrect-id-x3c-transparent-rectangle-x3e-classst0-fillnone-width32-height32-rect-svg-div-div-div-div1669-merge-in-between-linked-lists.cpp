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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* node = list1;
        ListNode* temp1 = new ListNode(-1);
        ListNode* temp2;
        int cnt=0;
        while(node!=NULL){
            // cout<<cnt<<endl;
            cnt++;
            if(cnt<=a){
                temp1->next = node;
        // cout<<temp1->next->val;
            }
            if(cnt==b+1){
                temp2 = node->next;
            }
            node = node->next;
        }
        temp1->next->next = list2;
        node = list2;
        while(node->next!=NULL){
            node = node->next;
        }
        node->next = temp2;
        return list1;
    }
};