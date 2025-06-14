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
    ListNode* sortList(ListNode* head) {
        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*,ListNode*)>>heap([](ListNode* a, ListNode* b){return a->val > b->val;});
        auto current = head;
        while(current){
            heap.push(current);
            current = current->next;
        }
        auto dummy = new ListNode(0);
        auto iter = dummy;
        while(!heap.empty()){
            auto node = heap.top();
            heap.pop();

            iter->next = node;
            iter = iter->next;
        }
        iter->next = nullptr;
        return dummy->next;
    }
};