class Solution {
public:
    int divide(int dividend, int divisor) {
        int power =31;
        bool isNegative = (dividend<0)^(divisor<0);
        unsigned long long absdividend = abs(static_cast<long long>(dividend));
        unsigned long long absdivisor = abs(static_cast<long long>(divisor));
        long long result =0;
        unsigned long long divisor_power = absdivisor<<power;
        while(absdividend >= absdivisor){
            while(divisor_power >absdividend){
                divisor_power >>=1;
                power--;
            }
            result += 1ULL<<power;
            absdividend -= divisor_power;
        }
        result = isNegative ? -static_cast<long long>(result) : static_cast<long long>(result);
        result = result > INT_MAX ? INT_MAX : static_cast<int>(result);
        return result;
    }
};