class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        const int len = nums.size();
        const int target = 0;
        if(len<3) return res;
        sort(nums.begin(),nums.end());
        int a,b,c;
        for(a=0;a<len;a++){
            b=a+1,c=len-1;
            if(a>0&&nums[a]==nums[a-1]) continue;
            if(a+2<len&&nums[a]+nums[a+1]+nums[a+2]>target){
                break;
            }
            if(c-1>a&&nums[a]+nums[c-1]+nums[c]<target){
                continue;
            }
            while(b<c){
                int sum=nums[a]+nums[b]+nums[c];
                if(sum<target){
                    ++b;
                    while(b<c&&nums[b]==nums[b-1]) ++b;
                }else if(sum>target){
                    --c;
                    while(b<c&&nums[c]==nums[c+1]) --c;
                }else{
                    res.push_back({nums[a],nums[b],nums[c]});
                    ++b;--c;
                    while(b<c&&nums[b]==nums[b-1]) ++b;
                    while(b<c&&nums[c]==nums[c+1]) --c;
                }
            }
        }
        return res;
    }
};

/*
1.用双指针
2.设置返回条件来剪去显然不能成立的情况
3.输出不得有重复的值，所以遍历处处要检查
*/
