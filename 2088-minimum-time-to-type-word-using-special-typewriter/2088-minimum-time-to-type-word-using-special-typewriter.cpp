class Solution {
public:
    int minTimeToType(string word) {
        int minSecs = 0;
        char initial = 'a';
        for(char c: word){
            int diff = abs(c-initial);
            minSecs+= min(diff, abs(26-diff))+1;
            initial = c;
        }
        return minSecs;
    }
};