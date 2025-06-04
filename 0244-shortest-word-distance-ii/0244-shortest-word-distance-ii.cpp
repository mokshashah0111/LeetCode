class WordDistance {
    private:
    vector<string>words;
    unordered_map<string,vector<int>>indexes;
public:
    WordDistance(vector<string>& wordsDict) {
        words = wordsDict;
        for(int i =0;i<words.size();i++){
            indexes[words[i]].emplace_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int> first = indexes[word1];
        vector<int>second = indexes[word2];

        int distance = INT_MAX;
        for(int i=0;i<first.size();i++){
            for(int j =0; j<second.size();j++){
                distance = min(distance, abs(first[i]-second[j]));
            }
        }
        return distance;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */