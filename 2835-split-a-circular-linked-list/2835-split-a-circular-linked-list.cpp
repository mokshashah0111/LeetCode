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
    vector<ListNode*> splitCircularLinkedList(ListNode* list) {
        if(!list) return {};
        if(list->next == list) return {list,nullptr};

        auto slow = list;
        auto fast = list;

        while(fast->next != list && fast->next->next!= list){
            slow = slow->next;
            fast= fast->next->next;
        }

        if(fast->next->next == list){
            fast = fast->next;
        }
        auto temp = slow->next;
        slow->next = list;

        fast->next = temp;
        return {list, temp};
    }
    
};