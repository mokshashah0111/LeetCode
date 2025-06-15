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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>result(k,nullptr);
        int size =0;
        auto current = head;
        while(current){
            current = current->next;
            size++;
        }
        int partsize = size/k;
        int extra = size%k;
        current = head;
        for(int i =0;i<k;i++){
            auto partHead = current;
            ListNode* prev = nullptr;
            int number= partsize + (i<extra ? 1:0);
            for(int j=0;j<number;j++){
                prev = current;
                if(current) current = current->next;
            }
            if(prev)prev->next = nullptr;
            result[i]  = partHead;
        }
        return result;
    }
};