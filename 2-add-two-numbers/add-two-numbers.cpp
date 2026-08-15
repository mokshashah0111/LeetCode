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
        ListNode* current1 = l1;
        ListNode* current2 = l2;
        ListNode* newHead = new ListNode(0);
        ListNode* result = newHead;
        int sum= 0;
        int value= 0;
        int carry = 0;
        while(current1 || current2){
            sum = (current1 ? current1->val : 0) + (current2 ? current2->val : 0) +carry;
            value = sum%10;
            carry = sum/10;

            ListNode* newNode = new ListNode(value);
            result->next = newNode;
            result = newNode;
            if(current1){
                current1 = current1->next;
            }
            if(current2){
                current2 = current2->next;
            }
        }
        if(carry){
            ListNode* carr = new ListNode(carry);
            result->next= carr;
        }
        return newHead->next;
    }
};