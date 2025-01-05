class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        if(arr.size() ==1){
            return {-1};
        }
        int max = -1;
        for(int i = arr.size()-1;i>=0;i--){
            int temp = arr[i];
            arr[i] = max;
            max = std::max(max,temp);
        }
        return arr;
    }
};