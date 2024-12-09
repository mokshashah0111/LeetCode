class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0;
        int odd=0;
        int index = 0;
        while(n){
            if(n%2 == 1){
                if(index%2==0){
                    even++;
                }
                else {
                    odd++;
                }
            }
            index++;
            n/=2;
        }
        return {even,odd};
    }
};