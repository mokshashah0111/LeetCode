class Solution {
public:
    int splitNum(int num) {
        string number = to_string(num);
        sort(number.begin(),number.end());
        string number1 = "";
        string number2 = "";

        for(int i = 0; i<number.size();i+=2){
            number1+=number[i];
            if(i+1< number.size()) number2+= number[i+1];
        }
        return stoi(number1)+stoi(number2);
    }
};