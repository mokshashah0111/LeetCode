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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;
        ListNode* current= new ListNode(0);
        current->next = head;
        ListNode* newHead = current;
        while(current){
            while(current->next && current->next->val == val){
                current->next = current->next->next;
            }
            current = current->next; 
        }
        return newHead->next;
    }
};