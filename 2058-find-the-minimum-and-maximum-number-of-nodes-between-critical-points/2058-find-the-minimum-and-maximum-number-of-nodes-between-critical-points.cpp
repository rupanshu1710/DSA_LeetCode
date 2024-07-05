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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int temp=-1;
        int temp1=0;
        int mn=INT_MAX;
        int mx=-1;
        if(!head || !head->next || !head->next->next)return {-1,-1};
        ListNode* curr = head->next;
        ListNode* prev = head;
        ListNode* next = curr->next;
        while(next){
            if(temp!=-1){
                temp++;
            }
            if(next->val>curr->val && curr->val<prev->val || next->val<curr->val && curr->val>prev->val){
                if(temp==-1)temp=0;
                if(temp1!=temp)mn = min(mn,temp-temp1);
                temp1 = temp;
                mx = temp;
            }
            prev = curr;
            curr = next;
            next = next->next;
        }
        if(mn==INT_MAX)mn=-1;
        if(mx==0)mx=-1;
        return {mn,mx};
    }
};