class Solution {
public:
    int mySqrt(int x) {
        long left=1,right=x;
        int result;
        while(left<right){
            long mid=(left+right)/2;
            long mul = mid*mid;
            if(mul==(long)x)  return mid;
            else if(mul<(long)x) left=mid+1;
            else right=mid-1;
        }
        if(left*left>(long)x) result=left-1;
        else result=left;
        return result;
    }
};
