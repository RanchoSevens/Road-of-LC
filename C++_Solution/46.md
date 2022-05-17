class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        vector<int> flag(len,1);
        vector<vector<int>> result;
        vector<int> temp;
        for(int i=0;i<len;++i){
            flag[i]=0;
            temp.push_back(nums[i]);
            dfs(nums,flag,temp,result,len);
            temp.pop_back();
            flag[i]=1;
        }
        return result;
    }
    void dfs(vector<int>& nums,vector<int> flag,vector<int>& temp,vector<vector<int>>& result,int len){
        if(temp.size()==len){
            result.push_back(temp);
        }
        for(int i=0;i<len;++i){
            if(flag[i]){
                flag[i]=0;
                temp.push_back(nums[i]);
                dfs(nums,flag,temp,result,len);
                temp.pop_back();
                flag[i]=1;
            }
        }
        return;
    }
};
/*
1.dfs
*/
