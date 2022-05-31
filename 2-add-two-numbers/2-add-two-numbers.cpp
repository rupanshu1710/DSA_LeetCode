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
    int Length(ListNode* l1)
    {
        if(!l1)return 0;
        return 1+Length(l1->next);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int lnt1 = Length(l1);
        int lnt2 = Length(l2);
        cout<<lnt1;
        if(lnt1==1 && lnt2==1)
        {
            l1->val = l1->val + l2->val;
            if(l1->val>9)
            {
                l1->val = l1->val%10;
                ListNode* temp = new ListNode(1);
                l1->next = temp;
            }
            return l1;
        }
        if(lnt1>=lnt2)
        {
            ListNode* p1 = (l1);
            ListNode* node;
            ListNode* ans = p1;
            ListNode* p2 = (l2);
            int carry = 0;
            while(p1 && p2)
            {
                p1->val = p1->val + p2->val + carry;
                carry = 0;
                if(p1->val>9)
                {
                    carry = 1;
                    p1->val = p1->val%10;
                }
                node = p1;
                p1 = p1->next;
                p2 = p2->next;
            }
            if(carry==1)
            {
                while(p1)
                {
                    p1->val += carry;
                    carry = 0;
                    if(p1->val>9)
                    {
                        carry = 1;
                        p1->val = p1->val%10;
                    }
                    node = p1;
                    p1 = p1->next;
                }
                if(carry==1)
                {
                    ListNode* temp = new ListNode(1);
                    node->next = temp;
                    carry=0;
                }
            }
            return ans;
        }
        else
        {
            ListNode* p1 = (l2);
            ListNode* node;
            ListNode* ans = p1;
            ListNode* p2 = (l1);
            int carry = 0;
            while(p1 && p2)
            {
                p1->val = p1->val + p2->val + carry;
                carry = 0;
                if(p1->val>9)
                {
                    carry = 1;
                    p1->val = p1->val%10;
                }
                p1 = p1->next;
                p2 = p2->next;
            }
            if(carry==1)
            {
                while(p1)
                {
                    p1->val += carry;
                    carry = 0;
                    if(p1->val>9)
                    {
                        carry = 1;
                        p1->val = p1->val%10;
                    }
                    node = p1;
                    p1 = p1->next;
                }
                if(carry==1)
                {
                    ListNode* temp = new ListNode(1);
                    node->next = temp;
                    carry=0;
                }
            }
            return ans;
        }
    }
};