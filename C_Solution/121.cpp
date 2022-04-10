class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> m;
        int result=0;
        int pl=prices.size();
        for(int i=0;i<pl;++i){
            if(i==0) m.push_back(prices[i]);
            else m.push_back(min(m[i-1],prices[i]));
        }
        for(int i=0;i<pl;++i){
            result=max(result,prices[i]-m[i]);
        }
        return result;
    }
};
