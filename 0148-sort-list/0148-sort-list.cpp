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
    ListNode* Merge(ListNode* a, ListNode* b){
        if(!a) return b;
        if(!b) return a;

        if(a->val < b->val){
            a->next =Merge(a->next,b);
            return a;
        }
        else{
            b->next = Merge(a,b->next);
            return b;
        }
        return nullptr;
    }

    ListNode* split(ListNode* head){
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            fast = fast->next->next;
            if(fast){
                slow = slow->next;
            }
        }

        ListNode* temp = slow->next;
        slow->next = nullptr;

        return temp;   
    }

public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* second = split(head);
        head = sortList(head);
        second = sortList(second);
        return Merge(head, second);        
    }
};