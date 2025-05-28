class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,int>freq;
        for(int& num: arr){
            freq[num]++;
        }
        for(int& x: arr){
            if(freq[x] ==0) continue;
            if(x<0 && x%2) return false;
            int y =x>0 ? x*2 : x/2;
            if(freq[y]<=0) return false;
            freq[x]--;
            freq[y]--;
        }
        return true;
    }
};