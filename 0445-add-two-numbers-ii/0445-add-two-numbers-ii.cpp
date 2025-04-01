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
        stack<ListNode*>st1;
        stack<ListNode*>st2;

        ListNode* current1 = l1;
        ListNode* current2= l2;
        ListNode* newHead = nullptr;

        while(current1){
            st1.push(current1);
            current1 = current1->next;
        }
        while(current2){
            st2.push(current2);
            current2 = current2->next;
        }
        int carry =0;
        while(!st1.empty() || !st2.empty() || carry){
            int val1 =0;
            int val2 = 0;

            if(!st1.empty()){
                val1 = st1.top()->val;
                st1.pop();
            }
            if(!st2.empty()){
                val2 = st2.top()->val;
                st2.pop();
            }
            int sum = carry + val1+val2;
            int value = sum%10; 
            carry = sum/10;
            ListNode* newNode = new ListNode(value);
            newNode->next = newHead;
            newHead = newNode;
        }
        return newHead;
    }
};