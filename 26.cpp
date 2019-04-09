// problem--Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        for(int i=1;i<nums.size();++i){
            if(nums[i]!=nums[k]){
                nums[++k]=nums[i];
            }
        }
        return nums.size()==0?k:(k+1);
    }
};
