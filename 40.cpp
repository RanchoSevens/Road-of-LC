class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        const int len = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        vector<int> count;
        dfs(candidates,count,result,len,target,0,0);
        return result;
    }
    void dfs(vector<int>& num,vector<int>& count,vector<vector<int>>& result,int len,int target,int pos,int sum){
        if(sum==target){
            result.push_back(count);
            return;
        }else if(sum>target){
            return;
        }else{
            for(int i=pos;i<len&&num[i]<=target;++i){
                int k=num[i];
                if(i!=pos&&num[i]==num[i-1]) continue;
                count.push_back(k);
                dfs(num,count,result,len,target,i+1,sum+k);
                count.pop_back();
            }
        }
    }
};
/*
1.相同元素第一个进入下一层递归-->处理重复
*/
