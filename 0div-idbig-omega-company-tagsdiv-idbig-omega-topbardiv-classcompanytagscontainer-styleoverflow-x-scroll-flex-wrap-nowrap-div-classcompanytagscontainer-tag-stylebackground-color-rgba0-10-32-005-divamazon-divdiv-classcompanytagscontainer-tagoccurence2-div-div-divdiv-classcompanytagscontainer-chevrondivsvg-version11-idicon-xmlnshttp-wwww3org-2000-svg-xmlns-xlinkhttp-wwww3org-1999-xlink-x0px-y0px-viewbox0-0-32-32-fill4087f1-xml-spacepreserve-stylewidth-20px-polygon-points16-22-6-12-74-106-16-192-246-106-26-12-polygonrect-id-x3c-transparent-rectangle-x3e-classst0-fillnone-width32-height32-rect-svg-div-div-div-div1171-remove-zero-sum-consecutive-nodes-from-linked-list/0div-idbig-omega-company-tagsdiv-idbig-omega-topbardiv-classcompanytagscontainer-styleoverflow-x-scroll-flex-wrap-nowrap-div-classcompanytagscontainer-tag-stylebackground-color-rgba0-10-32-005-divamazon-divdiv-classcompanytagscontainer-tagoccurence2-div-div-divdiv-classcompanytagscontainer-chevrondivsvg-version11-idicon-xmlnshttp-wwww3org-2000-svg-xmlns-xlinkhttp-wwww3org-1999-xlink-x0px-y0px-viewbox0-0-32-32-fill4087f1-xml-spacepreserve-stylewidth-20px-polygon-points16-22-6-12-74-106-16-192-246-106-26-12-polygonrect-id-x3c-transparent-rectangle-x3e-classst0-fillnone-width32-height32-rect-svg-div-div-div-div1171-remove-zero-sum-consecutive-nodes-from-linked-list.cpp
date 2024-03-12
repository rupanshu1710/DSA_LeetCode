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
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int,int>mp;
        map<int,int>mp2;
        map<int,ListNode*>mp1;
        ListNode* nod = head;
        while(nod!=NULL){
            // cout<<nod->val<<" ";
            nod = nod->next;
        }
        // cout<<endl;
        ListNode* node = head;
        int sum=0,i=0;
        while(node!=NULL){
            sum += node->val;
            if(sum==0){
                head = node->next;
            }
            else if(mp1.find(sum)!=mp1.end()){
                mp1[sum]->next = node->next;
                // cout<<node->val<<endl;
                // cout<<mp1[sum]->val<<" "<<sum<<endl;
                // // mp1.clear();
                // sum=0;
            }
            mp1[sum] = node;
            
            node = node->next;
        }
        mp1.clear();
        node = head;
        sum=0,i=0;
        while(node!=NULL){
            sum += node->val;
            if(sum==0){
                head = node->next;
            }
            else if(mp1.find(sum)!=mp1.end()){
                mp1[sum]->next = node->next;
                // cout<<node->val<<endl;
                // cout<<mp1[sum]->val<<" "<<sum<<endl;
                // mp1.clear();
                // sum=0;
            }
            mp1[sum] = node;
            
            node = node->next;
        }
        mp1.clear();
        node = head;
        sum=0,i=0;
        while(node!=NULL){
            sum += node->val;
            if(sum==0){
                head = node->next;
            }
            else if(mp1.find(sum)!=mp1.end()){
                mp1[sum]->next = node->next;
                // cout<<node->val<<endl;
                // cout<<mp1[sum]->val<<" "<<sum<<endl;
                // mp1.clear();
                // sum=0;
            }
            mp1[sum] = node;
            
            node = node->next;
        }
        // nod = head;
        // while(nod!=NULL){
        //     cout<<nod->val<<" ";
        //     nod = nod->next;
        // }
//         int j=i-1;
//         while(j>=0){
//             if(mp2[j]>1){
                
//             }
//         }
        return head;
    }
};