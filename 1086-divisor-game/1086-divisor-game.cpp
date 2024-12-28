class Solution {
public:
    bool divisorGame(int n) {
        int count = -1;
        while(n>1){
            if(n%2==0){
                count++;
                n -=1;
            } 
            else{
                for(int i =n-1;i>0;i--){
                    if(n%i==0){
                        count++;
                        n-=i;
                        break;
                    }
                }
            }
        }
        return count%2==0;
    }
};