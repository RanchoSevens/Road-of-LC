// problem--Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        for(int i=1;i<nums.size();++i){
            if(nums[i]!=nums[k]){
                nums[++k]=nums[i];
            }
        }
        return nums.size()==0?k:(k+1);
    }
};


/*
  1. 当仅当相邻数字不一致时更新id
*/



class Solution {
    public:
    int removeDuplicates(int A[], int n) {
        if(n < 2) return n;
        int id = 1;
        for(int i = 1; i < n; ++i) 
            if(A[i] != A[i-1]) A[id++] = A[i];
        return id;
    }
};
