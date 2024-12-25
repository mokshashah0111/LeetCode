class Solution {
public:
    int addDigits(int num) {

        int digit_1= num%10;
        int digit_2 = num/10;

        int sum = digit_1 +digit_2;

        while(sum%10 != sum){
            num = sum;
            digit_1 = num%10;
            digit_2 = num/10;
            sum = digit_1 +digit_2;
        }

        return sum;
    }
};