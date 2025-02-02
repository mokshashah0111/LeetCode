class Solution {
public:
    int myAtoi(string s) {
        bool isNegative=false;
        long ans=0;
        int i = 0;
        // if(isalpha(s[0])) return 0;
        while(i<s.length() && s[i] == ' ')i++;
        if(s[i] == '-'){
            isNegative = true;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }
        for(;i<s.length();i++){
            char c = s[i];
            if(c < '0' || c > '9') break;
            int digit = c-'0';
            ans = (ans<<3) + (ans<<1);
            ans += digit;
            if (isNegative && -ans < INT_MIN) return INT_MIN;
            if (!isNegative && ans > INT_MAX) return INT_MAX;
        }
        if(isNegative) ans = -ans;
        return ans;
    }
};