class Solution {
    private:
    bool helper(vector<int>& preorder , int& i, int min, int max){
        if(i==preorder.size()) return true;
        int root = preorder[i];
        if(root<=min || root>=max) return false;
        i++;
        return helper(preorder,i,min,root) || helper(preorder, i, root, max);
    }
public:
    bool verifyPreorder(vector<int>& preorder) {
        int i = 0;
        return helper(preorder, i, INT_MIN, INT_MAX);
        
    }
};