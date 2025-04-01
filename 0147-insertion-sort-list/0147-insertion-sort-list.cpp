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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head; 
        ListNode* sortedList = nullptr;

        ListNode* current = head;
        while(current){
            ListNode* next = current->next;
            if(!sortedList || current->val <= sortedList->val){
                current->next = sortedList;
                sortedList = current;
            }
            else{
                ListNode* temp = sortedList;
                while(temp->next && current->val > temp->next->val){
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
            current = next;
        }
        return sortedList;
    }
};