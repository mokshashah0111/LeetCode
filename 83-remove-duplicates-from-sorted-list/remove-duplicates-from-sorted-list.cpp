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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        ListNode* current= head;
        ListNode* newHead = new ListNode(0);
        newHead->next = current;
        
        while(current){
            while(current->next && current->next->val == current->val){
                current->next = current->next->next ? current->next->next : nullptr;
            }
            current = current->next;
        }
        return newHead->next;
    }
};