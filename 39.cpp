class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        const int len = candidates.size();
        vector<vector<int>> result;
        vector<int> count(len,0);
        int sum;
        for(int i=0;i<len;++i){
            if(candidates[i]<=target){
                sum = candidates[i];
                count[i]++;
                vector<int> ans = dfs(candidates,count,target,sum);
                if(!ans.empty()){
                    result.push_back(ans);
                }    
            }
            
        }
        return ans;
    }
    vector<int> dfs(vector<int>& candidates,vector<int>& count,int target,int sum){
        
    }
};
