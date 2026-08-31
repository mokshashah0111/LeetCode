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
        if(!head) return {-1,-1};
        if(!head->next->next) return {-1,-1};
        vector<int>criticals;
        ListNode* temp = head;
        ListNode* prev = temp;
        int nodecount =2;
        temp = temp->next;
        while(temp->next){
            if(temp->val < prev->val && temp->val < temp->next->val){
                criticals.emplace_back(nodecount);
            }
            else if(temp->val > prev->val && temp->val > temp->next->val){
                criticals.emplace_back(nodecount);
            }
            prev = temp;
            temp = temp->next;
            nodecount++;
        }
        if(criticals.size() <=1) return {-1,-1};
        int minDist = INT_MAX;
        for(int i=1;i<criticals.size();i++){
            minDist = min(minDist,criticals[i]-criticals[i-1]);
        }
        int maxDist = criticals[criticals.size()-1] - criticals[0];
        return {minDist,maxDist};
    }
};