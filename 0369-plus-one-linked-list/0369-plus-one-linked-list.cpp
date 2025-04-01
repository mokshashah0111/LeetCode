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
    ListNode* plusOne(ListNode* head) {
        stack<ListNode*>st;
        ListNode* current = head;

        while(current){
            st.push(current);
            current = current->next;
        }
        while(!st.empty()){
            ListNode* last = st.top();
            st.pop();

            if(last->val < 9){
                last->val+=1;
                return head;
            }
            else{
                last->val =0;
            }
        }
        ListNode* newHead = new ListNode(1);
        newHead->next = head;
        return newHead;
    }
};