class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>freq;
        for(char& c:s){
            freq[c]++;
        }
        priority_queue<pair<int,char>>maxHeap;
        for(auto& it: freq){
            if(it.second > floor((s.size()+1) /2)) return "";
            maxHeap.push({it.second,it.first});
        }

        string result;
        while(maxHeap.size()>1){
            auto [count1,ch1] = maxHeap.top();
            maxHeap.pop();
            auto [count2, ch2] =  maxHeap.top();
            maxHeap.pop();

            result+=ch1;
            result+=ch2;

            if(count1-1>0)maxHeap.push({count1-1,ch1});
            if(count2-1>0)maxHeap.push({count2-1,ch2});
        }
        if(!maxHeap.empty()){
            auto [count,ch] = maxHeap.top();
            if(count>1) return "";
            result+=ch;
        }
        return result;
    }
};