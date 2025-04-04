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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>result;
        ListNode* current = head;
        int listsize =0;

        while(current){
            current= current->next;
            listsize++;
        }
        current =head;

        for(int i =0; i<listsize-1;i++){
            ListNode* temp = current->next;
            
            while(temp && current->val >= temp->val){
                temp = temp->next;
            }
            result.emplace_back(temp ? temp->val : 0);
            current = current->next;
        }
        result.emplace_back(0);
        return result;
    }
};