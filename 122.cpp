class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int len = prices.size();
        for(int i=1;i<len;++i){
            if(prices[i-1]<prices[i]){
                profit += (prices[i]-prices[i-1]);
            }
        }
        return profit;
    }
};
/*
1.从第二天开始，如果价格比第一天高，就前天买进今天卖出，计入利润，遍历即可
*/
