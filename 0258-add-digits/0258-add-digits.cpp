class Solution {
public:
    int addDigits(int num) {
        while(num%10 != num){
            int digit_1 = num%10;
            int digit_2 = num/10;
            num = digit_1 +digit_2;
        }
        return num;
    }
};