class Solution {
public:
    int findMin(vector<int>& nums) {
        int left,right;
        const int l = nums.size();
        left=0; right=l-1;
        while(left<right){
            if(nums[right]>nums[left]) return nums[left];
            int mid=(left+right)/2;
            if(nums[mid]>nums[left]) left=mid+1;
            else if(nums[mid]<nums[left]) right=mid;
            else left++;
        }
        return nums[left];
    }
};

/*
1.折半查找，对于nums[left]<nums[right]以及nums[left]==nums[mid]情况特殊处理
*/
