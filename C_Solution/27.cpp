class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res=0,len=nums.size();
        for(int i=0;i<len;++i){
            if(nums[i]!=val){
                nums[res++]=nums[i];
            }
        }
        return res;
    }
};
