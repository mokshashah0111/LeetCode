class Solution {
public:
    int tripletCount(vector<int>& a, vector<int>& b, vector<int>& c) {
        int count=0;
        for(int number :a){
            int XOR = 0;
            for(int numberB : b){
                for(int numberC : c){
                    XOR = number ^ numberB ^ numberC;
                    int temp = XOR;
                    int set = 0;
                    while(temp){
                        set+=temp%2;
                        temp/=2;
                    }
                    if(set%2 == 0)count++;
                }
            }
        }
        return count;
    }
};