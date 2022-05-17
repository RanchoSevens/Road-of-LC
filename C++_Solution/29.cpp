class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN&&divisor==-1) return INT_MAX;
        long dvd=labs(dividend),dvs=labs(divisor),ans=0;
        int sgn = (dividend>0)^(divisor>0)?-1:1;
        while(dvd>=dvs){
            long tmp=dvs,l=1;
            while((tmp<<1)<=dvd){
                tmp<<=1;
                l<<=1;
            }
            dvd-=tmp;
            ans+=l;
        }
        return sgn*ans;
    }
};
