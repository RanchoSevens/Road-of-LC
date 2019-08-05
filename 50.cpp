class Solution {
public:
    double myPow(double x, int n) {
        double res=1;
        double eps = 1e-8;
        long num = (long)n;
        if(num<0){
            x=1/x;
            num=-num;
        }
        if(fabs(fabs(x)-1)<eps)  return num%2==0?fabs(x):x; 
        while(num>0){
            if(num&1){
                res=res*x;
            }
            num>>=1;
            x*=x;
            if(fabs(res)<eps) break;
        }
        return res;
    }
};
/*
1.处理好特殊情况即可
2.可以用迭代法，递归实现快速幂亦可
*/
