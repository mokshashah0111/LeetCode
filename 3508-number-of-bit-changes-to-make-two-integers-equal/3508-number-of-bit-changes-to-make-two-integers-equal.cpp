class Solution {
public:
    int minChanges(int n, int k) {
        int count=0;
        while(n || k){
            int BitN = n%2;
            int BitK = k%2;
            if((BitN ^ BitK) !=0){
                if(BitN != 1) return -1;
                else count++;
            }
            n /=2;
            k/=2;
        }
        return count;
    }
};