class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left,right;
        const int l=nums.size();
        left=0; right=l-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target) return true;

            if(nums[mid]>nums[left]){
                if(target==nums[left]) return true;
                if(target<nums[mid]&&target>nums[left]){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }else if(nums[mid]<nums[left]){
                if(target==nums[right]) return true;
                if(target>nums[mid]&&target<nums[right]){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }else{
                left++;
            }
        }
        return false;
    }
};
/*
1.比33题多了一个步骤，即当nums[left]==nums[right]的时候，直接left++，不用O(n)的复杂度判断是否有序
*/
