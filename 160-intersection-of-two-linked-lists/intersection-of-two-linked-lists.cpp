/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int getLength(ListNode* head){
        int len =0;
        while(head){
            head = head->next;
            len++;
        }
        return len;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = getLength(headA);
        int lengthB = getLength(headB);

        ListNode* currentA = headA;
        ListNode* currentB = headB;

        if(lengthA > lengthB){
            while(lengthA != lengthB){
                currentA = currentA->next;
                lengthA--;
            }
        }
        else{
            while(lengthB != lengthA){
                currentB = currentB->next;
                lengthB--;
            }
        }

        while(currentA && currentB){
            if(currentA == currentB) return currentA;
            currentA = currentA->next;
            currentB = currentB->next;
        }
        return nullptr;
    }
};