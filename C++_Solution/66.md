class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int inp=1;
        for(int i=len-1;i>-1;i--){
            level(inp,digits,i);
        }
        vector<int> result;
        if(inp) result.push_back(inp);
        for(int i=0;i<len;++i){
            result.push_back(digits[i]);
        }
        return result;
    }
    void level(int& inp,vector<int>&digits,int i){
        int k=inp+digits[i];
        inp = k/10;
        digits[i]=k%10;
        return;
    }
};
