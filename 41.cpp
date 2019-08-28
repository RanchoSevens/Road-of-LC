class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int result=1;
        for(int i=0;i<n;++i){
            int k = nums[i];
            while(k>0&&k<n+1&&i!=k-1&&nums[k-1]!=k){
                int temp = nums[k-1];
                nums[k-1]=k;
                nums[i] = temp;
                k = nums[i];
            }
        }
        for(int i=0;i<n;++i){
            if(nums[i]!=i+1){
                break;
            }else{
                result++;
            }
        }
        return result;
    }
};
