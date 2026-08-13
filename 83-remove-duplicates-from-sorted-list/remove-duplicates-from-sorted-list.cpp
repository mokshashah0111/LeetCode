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
        ListNode* prev = current;

        int val = current->val;
        newHead->next = current;
        current = current->next;

        while(current){
            if(current->val != val){
                prev->next = new ListNode(current->val);
                prev = prev->next;
                val = current->val;
            }
            else prev->next = nullptr;
            current= current->next;
        }
        return newHead->next;
    }
};