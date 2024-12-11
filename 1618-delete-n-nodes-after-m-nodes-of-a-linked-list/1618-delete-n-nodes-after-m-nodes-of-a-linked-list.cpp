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
    void deleteNodesHelper(ListNode* head, int m, int n){
        if(!head) return;
        ListNode* current = head;
        for(int i = 1; i<m && current;i++){
            current = current->next;
        }
        if(!current) return;
        ListNode* temp = current->next;

        for(int i = 0; i<n && temp;i++){
            ListNode* dlt = temp;
            temp = temp->next;
            delete dlt;
        }
        current->next = temp;
        
        deleteNodesHelper(current->next,m,n);
    }
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        deleteNodesHelper(head,m,n);
        return head;
    }
};