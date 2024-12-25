class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int bill_F =0;
        int bill_T = 0;
        int bill_Tw = 0;

        int ptr= 0;
        while(ptr < bills.size()){
            if(bills[ptr] == 5) {
                bill_F++;
                ptr++;
            }
            else if(bills[ptr] == 10){
                if(bill_F > 0) {
                    bill_F--;
                    bill_T++;
                    ptr++;
                }
                else return false;
            }
            else{
                if(bill_T > 0 && bill_F >0){
                    bill_F--;
                    bill_T--;
                }
                else if(bill_F >=3){
                    bill_F -= 3;
                }
                else return false;
                ptr++;

            }
        }
        return true;
    }
};