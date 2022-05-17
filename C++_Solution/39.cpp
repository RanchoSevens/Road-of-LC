class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        const int len = candidates.size();
        vector<vector<int>> result;
        vector<vector<int>> nodr;
        vector<int> count;
        int sum=0;
        for(int i=0;i<len;++i){
            int k=candidates[i];
            count.push_back(k);
            dfs(candidates,result,count,target,sum+k,i,len);  
            count.pop_back();
        }
        return result;
    }
    void dfs(vector<int>& candidates,vector<vector<int>> &result,vector<int> &count,int target,int sum,int i,int len){
        if(sum==target){
            result.push_back(count);
            return;
        }
        if(sum>target) return;
        for(int j=i;j<len;++j){
            int k=candidates[j];
            count.push_back(k);
            dfs(candidates,result,count,target,sum+k,j,len);
            count.pop_back();
        }
        return;
    }
};
