/*
1.代码一定要严谨
2.memset(matrix[i],0,sizeof(matrix[i])); 会出问题，所以可能sizeof一个二元数组的一元操作，不可以
      sizeof(matrix[0]) = 8
      sizeof(nint) = 12
*/
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int m=matrixSize;
    int n=*matrixColSize;
    int cflag[n];
    int i,j,rflag;
    memset(cflag,-1,sizeof(cflag));
    printf("\n");
    for(i=0;i<m;++i){
        rflag=1;
        for(j=0;j<n;++j){
            if(matrix[i][j]==0){
                rflag=0;
                cflag[j]=0;
            }
        }
        if(rflag==0) memset(matrix[i],0,n*sizeof(int));
    }
    for(j=0;j<n;++j){
        if(cflag[j]==0){
            for(i=0;i<m;++i) matrix[i][j]=0;
        }
    }
}
/*
1.行与列不能同时清零
2.行与列出现一个零，则应清零
3.误导项：被清零后作为其他位置的判断项
4.逻辑：第一行&第一列作为标志位
5.特殊处理1：第一列特殊处理，循环遍历时将第一列单独处理，原因在第一列若向上标志位取零(matrix[0][0]=0)，则第一行数据会因此全零
6.特殊处理2：为不使得前面处理的位置成为后面的误导，从右至左，从下至上
*/
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int m=matrixSize;
    int n=*matrixColSize;
    int i,j,col0=1;
    for(i=0;i<m;++i){
        if(matrix[i][0]==0) col0=0;
        for(j=1;j<n;++j){
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
    }
    for(i=m-1;i>-1;--i){
        for(j=n-1;j>0;--j){
            if(matrix[i][0]==0||matrix[0][j]==0){
                matrix[i][j]=0;
            }
        }
        if(col0==0) matrix[i][0]=0;
    }
}
