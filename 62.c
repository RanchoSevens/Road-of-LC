/*
1.熟悉递归调用、为递归调用
2.在使用递归之前函数需先声明
3.排列组合相关知识
*/
long int comb(int m,int n,long int total);
long int frac(int n,long int total);

int uniquePaths(int m, int n){
    if(m==1||n==1) return 1;
    if(m<n){
        int k=m;
        m=n;
        n=k;
    }
    return comb(m-1,n-1,1)/frac(n-1,1);
}

long int comb(int m,int n,long int total){
    if(n==0) return total;
    return comb(m,n-1,total*(m+n));
}
long int frac(int n,long int total){
    if(n==1) return total;
    return frac(n-1,total*n);
}
/*
1.dp的简单使用
*/
int uniquePaths(int m, int n){
    int k=m;
    m=n;
    n=k;
    int dp[m][n];
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            dp[i][j]=1;
        }
    }
    for(int i=1;i<m;++i){
        for(int j=1;j<n;++j){
            dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}
