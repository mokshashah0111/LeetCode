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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int,int>freq;
        auto current = head;
        while(current){
            freq[current->val]++;
            current = current->next;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        auto iter = dummy;
        current = dummy->next;
        while(current){
            if(freq[current->val] >1){
                iter->next = current->next;
                current->next = nullptr;
                current = iter;
            }
            iter = current;
            current = current->next;
        }
        return dummy->next;
    }
};