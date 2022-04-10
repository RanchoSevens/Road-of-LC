#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        const int len = nums.size();
        int maxm = -1;
        for(int i=1;i<len;++i){
            if(nums[i]>nums[i-1]){
                maxm=i-1;
            }
        }
        if(maxm==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        if(maxm+2==len) {
            swap(nums[maxm], nums[maxm + 1]);
            return;
        }
        int minn;
        for(int i=len-1;i>maxm;--i){
            if(nums[i]>nums[maxm]){
                minn=i;
                break;
            }
        }
        for(int i=len-1;i>maxm;--i){
            if(nums[i]< nums[minn]&&nums[i]>nums[maxm]){
                minn=i;
            }
        }
        swap(nums[maxm],nums[minn]);
        vector<int>::iterator it = nums.begin();
        for(int i=0;i<=maxm;++i){
            it++;
        }
        sort(it,nums.end());
        return;
    }
};
/*
1.字典序的排序规则，从左至右找正序，从右至左找逆序
2.正序最大与逆序恰好比正序稍大的数交换
3.交换后该位置后的逆序倒成正序，整个序列为所求序列
*/

int main() {
    Solution S1;
    vector<int> a={1,3,2};
    S1.nextPermutation(a);
    for(int i=0;i<3;++i){
        printf("%d ",a[i]);
    }
    return 0;
}
