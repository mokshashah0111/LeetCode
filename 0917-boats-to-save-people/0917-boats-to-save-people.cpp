class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i =0;
        int j = people.size()-1;
        int minBoats=0;
        while(i<=j){
            minBoats++;
            if(people[i]+people[j] <=limit){
                i++;
            }
            j--;
        }
        return minBoats;
    }
};