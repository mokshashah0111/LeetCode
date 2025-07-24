class Solution {
    bool canEat(int b, int h, vector<int>& piles){
        double t= 0;
        for(int i: piles){
            t+=ceil((double)i/b);
        }
        return (int)t<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int m = piles.size();

        int low =1;
        int high  = piles[m-1];
        int minimum = high;

        while(low<high){
            int mid = low+(high-low)/2;

            if(canEat(mid,h,piles)){
                minimum = mid;
                high = mid;
            }
            else low = mid+1;
        }
        return minimum;
    }
};