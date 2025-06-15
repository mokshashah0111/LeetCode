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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<ListNode*>arr;
        auto current = head;

        while(current){
            arr.emplace_back(current);
            current = current->next;
        }
        swap(arr[k-1],arr[arr.size()-k]);
        ListNode* dummy = new ListNode(0);
        auto iter = dummy;

        for(int i =0; i<arr.size();i++){
            iter->next = arr[i];
            iter = iter->next;
        }
        iter->next = nullptr;
        return dummy->next;
    }
};