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
    private:
        int getlength(ListNode* head){
            int l=1;
            ListNode*curr=head;
            while(curr!=NULL)
            {
                l++;
                curr=curr->next;
            }
            return l;
        }
        
       ListNode*traverse(ListNode* head, int n) {
           int cnt=1;
           ListNode*temp=head;
           while(cnt!=n)
           {
               temp=temp->next;
               cnt++;
           }
           return temp;
       }
        
    
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int len=getlength(head);
        ListNode*start=traverse(head,k);
        ListNode*end=traverse(head,len-k);
//         ListNode*temp1= new ListNode(-1);
        
//         temp1->val=start->val;
//         start->val=end->val;
//         end->val=temp1->val;
        
        swap(start->val,end->val);
        return head;
    }
};