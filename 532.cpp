class Solution {
public:
    int binarySearch(vector<int>& nums,int left,int right,int x){
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid] > x) right = mid - 1;
            else if(nums[mid] < x) left = mid + 1;
            else{
                return mid;
            }
        }
        return -1;
    }
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count = 0;
        for(int i=0;i<nums.size();++i){
            if(i&&nums[i]==nums[i-1]) continue;
            int left = i+1,right= nums.size()-1;
            if(binarySearch(nums,left,right,nums[i]+k)>0) count++;
        }
        return count;
    }
};
