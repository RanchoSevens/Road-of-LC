

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
1.代码一定要严谨
2.memset(matrix[i],0,sizeof(matrix[i])); 会出问题，所以可能sizeof一个二元数组的一元操作，不可以
      sizeof(matrix[0]) = 8
      sizeof(nint) = 12
*/
