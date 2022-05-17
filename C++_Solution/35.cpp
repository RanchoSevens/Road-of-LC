// problem--Search Insert Position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int flag=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=target){
                flag=i;
                break;
            }
        }
        if(flag==-1)    flag=nums.size();
        return flag;
    }
};
