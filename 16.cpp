class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int dis=INT_MAX;
        int a,b,c;
        const int len = nums.size();
        sort(nums.begin(),nums.end());
        for(a=0;a<len;a++){
            if(a!=0&&nums[a]==nums[a-1]) continue;
            b=a+1; c=len-1;
            while(dis!=0&&b<c){
                int ndis=nums[a]+nums[b]+nums[c]-target;
                int sum=nums[a]+nums[b]+nums[c];
                if(abs(ndis)<abs(dis)){
                    dis=ndis;
                    if(dis>0){
                        --c;
                        while(b<c&&nums[c]==nums[c+1]) --c;
                    }else if(dis<0){
                        ++b;
                        while(b<c&&nums[b]==nums[b-1]) ++b;
                    }else break;
                }else if(sum<target){
                    ++b;
                    while(b<c&&nums[b]==nums[b-1]) ++b;
                }else{
                    --c;
                    while(b<c&&nums[c]==nums[c+1]) --c;
                }
            }
        }
        return dis+target;
    }
};
/*
1.仿照15题，只是遍历时存储离目标target的距离
*/
