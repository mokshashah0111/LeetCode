class Solution {
public:
    int minimumSum(int num) {
        vector<int>digits;
        while(num !=0){
            digits.emplace_back(num%10);
            num /=10;
        }
        sort(digits.begin(),digits.end());
        int number1 = (digits[0] * 10) + digits[2];
        int number2 = (digits[1] *10) + digits[3];

        return number1+number2;
    }
};