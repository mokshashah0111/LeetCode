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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head->next->next) return {-1,-1};
        int nodeCount =2;
        int firstCritical = -1;
        int prevCritical = -1;
        int currCritical = -1;

        ListNode* temp = head;
        ListNode* prev = temp;
        temp =temp->next;
        int minDist = INT_MAX;

        while(temp->next){
            if((temp->val < prev->val && temp->val < temp->next->val) || (temp->val > prev->val && temp->val > temp->next->val)){
                if(firstCritical == -1){
                    firstCritical = nodeCount;
                    currCritical = nodeCount;
                }
                else{
                    prevCritical = currCritical;
                    currCritical = nodeCount;
                }
            }
            if(prevCritical != -1 && currCritical != -1){
                minDist = min(minDist, currCritical-prevCritical);
            }
            prev = temp;
            temp = temp->next;
            nodeCount++;
        }
        if(minDist == INT_MAX) return {-1,-1};
        int maxDist = currCritical - firstCritical;
        return {minDist, maxDist};
    }
};