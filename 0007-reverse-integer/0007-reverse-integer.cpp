class Solution {
public:
    int reverse(int x) {
        int max = INT_MAX;
        int ans =0;
        while(x!=0){
            int pop = x%10;
            x/=10;
            if(ans > max/10 || (ans == max && pop >7)){
                return 0;
            }
            if(ans <INT_MIN/10 || (ans==INT_MIN && pop < -8)) return 0;
            ans = ans*10 + pop;
        }
        return ans;
        
    }
};