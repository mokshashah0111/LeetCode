class Solution {
public:
    bool isPrime(int n ){
        if(n<=1) return false;
        if(n == 2) return true;
        if(n%2==0) return false;
        for(int i = 3; i<=std::sqrt(n);i+=2){
            if(n%i == 0) return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int prime = 0;
        for(int i = 0; i<nums[0].size(); i++){
            int num = nums[0+i][0+i];
            int num2 = nums[i][nums.size()-i-1];
            if(isPrime(num)){
                prime = std::max(prime,num);
            }
            if(isPrime(num2)){
                prime = std::max(prime,num2);
            }
        }
        return prime;
    }
};