class Solution {
    private:
public:
    int sum;
    int size;
    vector<double>cdf;
    Solution(vector<int>& w) {
        sum=0;
        size = w.size();
        cdf.resize(size);

        for(int i =0;i<size;i++){
            sum+=w[i];
        }
        cdf[0] = static_cast<double>(w[0])/sum;
        for(int i =1;i<size;i++){
            cdf[i] = cdf[i-1]+static_cast<double>(w[i])/sum;
        }
        // std::srand(std::time(0));
    }
    
    int pickIndex() {
        double r = static_cast<double>(std::rand()) / (RAND_MAX + 1.0);

        for(int i =0;i<size;i++){
            if(r<cdf[i])return i;
        }
        return size-1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */