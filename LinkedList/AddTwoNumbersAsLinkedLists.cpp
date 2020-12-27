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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { 
        int carry = 0;
        
        ListNode* dummyl3 = new ListNode(0);
        auto current1 = l1;
        auto current2 = l2;
        auto current3 = dummyl3;
        
        int flagl1 = 0;
        int flagl2 = 0;
       while (current1 != nullptr || current2!= nullptr){             
            int x = (current1 != nullptr) ? current1->val : 0;
           int y = (current2 != nullptr)? current2->val:0;
           int sum = x+y+carry;
           carry = sum/10;
           current3->next = new ListNode (sum%10);
           current3 = current3->next;
           if (current1 != nullptr) current1 = current1->next;
           if (current2!= nullptr) current2 = current2->next; 
       } 
        
        if (carry > 0) current3->next = new ListNode(carry);
        return dummyl3->next;
    }
};