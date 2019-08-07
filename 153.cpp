class Solution1 {
public:
    int findMin(vector<int>& nums) {
        const int len = nums.size();
        int result=len-1;
        while(result-1>=0){
            if(nums[result]<nums[result-1]) break;
            --result;
        }
        return nums[result];
    }
};
class Solution2 {
public:
    int findMin(vector<int>& nums) {
        int left,right;
        const int len = nums.size();
        left=0,right=len-1;
        if(nums[left]<nums[right]) return nums[left];
        while(left+1<right){
            int mid=(left+right)/2;
            if(nums[left]<nums[mid]) left=mid;
            else right=mid;
        }
        return min(nums[left],nums[right]);
    }
};

/*
1.最简单的方法，遍历
2.二分，此时需要注意退出条件是left+1<right而非left<right
*/
