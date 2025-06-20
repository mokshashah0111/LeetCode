class Solution {
public:
    int calculate(string s) {
    
    unordered_map<char,int> precedence = {{'+',1},{'-',1},{'*',2},{'/',2}};
        stack<char>operations;
        stack<int>num;
        int curr =0;
        s+='#';
        for(char& c: s){
            if(c==' ')continue;
            else if(isdigit(c))curr = curr*10+ (c-'0');
            else{
                num.push(curr);
                while(!operations.empty() && precedence[c] <= precedence[operations.top()]){
                    int num1= num.top();num.pop();
                    int num2 = num.top();num.pop();
                    char op = operations.top();operations.pop();

                    if(op=='/')num.push(num2/num1);
                    else if(op=='*')num.push(num2*num1);
                    else if(op =='+')num.push(num2+num1);
                    else num.push(num2- num1);
                }
                operations.push(c);
                curr =0;
            }
        }
        return num.top();
    }
};