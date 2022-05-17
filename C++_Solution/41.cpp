class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int result=1;
        for(int i=0;i<n;++i){
            int k = nums[i];
            while(k>0&&k<n+1&&i!=k-1&&nums[k-1]!=k){
                int temp = nums[k-1];
                nums[k-1]=k;
                nums[i] = temp;
                k = nums[i];
            }
        }
        for(int i=0;i<n;++i){
            if(nums[i]!=i+1){
                break;
            }else{
                result++;
            }
        }
        return result;
    }
};
/*
1.用一个循环来交换每个数到他应该在的位置.
2.交换完后从前向后遍历，第一个数组下标+1 != 值的时候，这个数组下标+1就是我们所要的值.
*/
