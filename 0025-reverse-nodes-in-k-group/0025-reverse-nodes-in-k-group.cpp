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
    ListNode* reverseHelper(ListNode* head, int k){
        ListNode* current = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* temp = head;

        for(int i = 0; i<k;i++){
            if(!temp) return head;
            temp = temp->next;
        }
        for(int i = 0; i<k ;i++){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        if(next){
            head->next = reverseHelper(next, k);
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverseHelper(head,k);
    }
};