class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index = -1;
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(target==nums[low]) return low;
            if(target==nums[high]) return high;
            if(target==nums[mid]) return mid;
            if(nums[mid]>nums[low]){//pivot在mid右
                if(target>nums[mid]) low=mid+1;
                else{
                    if(target<nums[low]) low=mid+1;
                    else high=mid-1;
                }
            }else{//pivot在mid左
                if(target<nums[mid]) high=mid-1;
                else{
                    if(target<nums[low]) low=mid+1;
                    else high=mid-1;
                }
            }
        }
        return index;
    }
};
/*
1.折半查找的变体
*/
