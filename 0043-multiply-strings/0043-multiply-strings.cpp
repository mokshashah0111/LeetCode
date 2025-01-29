class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int>result(num1.size()+num2.size(),0);
        int sign = num1.front()<0 || num2.front()<0 ? -1 : 1;
        for(int i = num1.size()-1;i>=0;i--){
            for(int j = num2.size()-1;j>=0;j--){
                result[i+j+1] += (num1[i]-'0') * (num2[j]-'0');
                result[i+j] += result[i+j+1]/10;
                result[i+j+1] %=10;
            }
        }
        auto it = find_if(result.begin(),result.end(),[](int x) {return x!=0;});
        if(it == result.end()) return "0";
        else{
            result.erase(result.begin(),it);
        }
        string ans;
        for(int num:result){
            ans+=num+'0';
        }
        return ans;
    }
}; 
