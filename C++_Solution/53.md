class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> sums(len,0);
        int result=INT_MIN;
        for(int i=0;i<len;++i){
            if(i==0) sums[i]=nums[i];
            else    sums[i]=(sums[i-1]>0?sums[i-1]+nums[i]:nums[i]);
            result=max(result,sums[i]);
        }
        return result;
    }
};
