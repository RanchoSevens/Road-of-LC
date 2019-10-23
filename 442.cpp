class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for(int i=0;i<nums.size();++i){
            int k = nums[i];
            if(nums[abs(k)-1]>0) nums[abs(k)-1]*=-1;
            else result.push_back(abs(k));
        }
        return result;
    }
};
