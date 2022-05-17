class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(int num:nums) sum+=num;
        if(k<=0||sum%k) return false;
        vector<int> unvis(nums.size(),1);
        return canPartition(nums,unvis,0,0,k,0,sum/k);
    }
    static bool canPartition(vector<int>& nums,vector<int>& unvis,int cur_sum,int cur_num,int k,int sp,int target){
        if(k==1) return true;
        if(cur_sum==target && cur_num > 0){
            // for(int i=0;i<nums.size();++i){
            //     if(!unvis[i]) cout<<nums[i]<<" ";
            // }
            // cout<<endl;
            return canPartition(nums,unvis,0,0,k-1,0,target);
        }
        if(cur_sum>target) return false;
        for(int i=sp;i<nums.size();++i){
            if(unvis[i]){
                unvis[i]=0;
                if(canPartition(nums,unvis,cur_sum+nums[i],++cur_num,k,i+1,target)) return true;
                unvis[i]=1;
            }
        }
        return false;
    }
};
//sp用来记录当前组遍历到的下标，从这个下标开始添加新的数到这个组中
//遇到第一个分组成功就返回，剪枝
