class Solution {
public:
    int maxProduct(int n) {
        int firstmax=INT_MIN;
        int secondmax = INT_MIN;

        while(n){
            int digit = n%10;
            n /=10;

            if(firstmax ==INT_MIN) firstmax = digit;
            else if(firstmax < digit){
                secondmax = firstmax;
                firstmax = digit;
            }
            else if(firstmax >= digit && (secondmax<digit || secondmax ==INT_MIN))secondmax = digit;
        }
        return firstmax*secondmax;
    }
};