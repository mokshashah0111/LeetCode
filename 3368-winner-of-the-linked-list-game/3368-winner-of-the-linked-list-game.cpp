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
    
    string gameResult(ListNode* head) {
        int countOdd = 0;
        int countEven = 0;

        ListNode* evenHead = head;
        ListNode* oddHead = head->next;
        while(evenHead && oddHead){
            if(evenHead->val > oddHead->val){
                countEven++;
            }
            else if(evenHead->val < oddHead->val) countOdd++;

            ListNode* temp = oddHead->next;
            evenHead = temp;
            oddHead = temp ? (temp->next ? temp->next : nullptr) : nullptr;
        }
        if(countEven == countOdd) return "Tie";
        else if(countEven > countOdd) return "Even";
        else return "Odd";
    }
};