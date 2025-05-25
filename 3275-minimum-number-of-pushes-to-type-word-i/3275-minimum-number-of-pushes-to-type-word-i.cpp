class Solution {
public:
    int minimumPushes(string word) {
        if(word.size() <= 8) return word.size();
        unordered_map<char,int>push;
        int initial =0;
        int index =0;

        while(index<word.size()){
            if(index%8==0) initial++;
            if(push.find(word[index]) == push.end()){
                push[word[index]] = initial;
            }
            index++;
        }
        int minPush =0;
        for(auto& c: word){
            minPush+=push[c];
        }
        return minPush;
    }
};