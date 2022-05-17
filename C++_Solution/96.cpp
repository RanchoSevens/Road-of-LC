class Solution {
public:
    int numTrees(int n) {
        vector<int> count(n+1,0);
        count[0]=1;
        count[1]=1;
        for(int i=2;i<=n;++i){
            for(int j=0;j<i;++j){
                count[i]+=count[j]*count[i-1-j];
            }
        }
        return count[n];
    }
};
/*
1.找规律，问题转化为一维动态规划
*/
