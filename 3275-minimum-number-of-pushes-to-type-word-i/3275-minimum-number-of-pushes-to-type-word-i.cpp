class Solution {
public:
    int minimumPushes(string word) {
        int initial=0;
        int index =0;
        int minPush=0;

        for(int i =0;i<word.size();i++){
            if(i%8==0)initial++;
            minPush+=initial;
        }
        return minPush;
    }
};