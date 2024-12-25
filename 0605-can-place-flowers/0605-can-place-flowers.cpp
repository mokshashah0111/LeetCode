class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        bool prev = false;
        int ptr = 0;

        while(ptr<flowerbed.size()){
            if(n==0) return true;
            if(flowerbed[ptr] == 1){
                ptr++;
                prev = true;
            }
            else {
                if(prev == false) {
                    if(ptr+1<flowerbed.size()){
                        if(flowerbed[ptr+1] ==0){
                            flowerbed[ptr] = 1;
                            prev = true;
                            ptr++;
                            n--;
                        }
                        else {
                            ptr++;
                            prev = true;
                        }
                    }
                    else {
                        if(prev == false){      
                            flowerbed[ptr]=1;
                            n--;
                        }
                    }
                }
                else{
                    prev = false;
                    ptr++;
                } 
            }
            
        }
        return n==0;
    }
};