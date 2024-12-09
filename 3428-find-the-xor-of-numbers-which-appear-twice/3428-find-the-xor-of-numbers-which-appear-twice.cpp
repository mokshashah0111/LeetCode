class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<bool>visited(50,false);
        int Xor=0;
        for(int number:nums){
            if(visited[number]){
                Xor ^=number;
            }
            visited[number] = true;
        }
        return Xor;
    }
};