/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){

    if(matrixSize==0){
        *returnSize=0;
        return NULL;
    }
    
    int rnum = sizeof(int)*(matrixSize*(*matrixColSize));
    int *res=(int *)malloc(rnum);
    
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m=matrixSize;
    int n=*matrixColSize;
    
    int nSteps[2];
    nSteps[0]=*matrixColSize;
    nSteps[1]=matrixSize-1;
    // printf("%d$$$%d\n",nSteps[0],nSteps[1]);
    int iDir=0;
    int im=0;
    int in=-1;
    int nowStep=nSteps[iDir%2];
    int ires=0;
    
    while(nowStep){
        for(int i=0;i<nowStep;++i){
            // if(){
                
            // }
            im+=dir[iDir][0];
            in+=dir[iDir][1];
            printf("im = %d $$$ in = %d\n",im,in);
            res[ires++]=matrix[im][in];
        }
        printf("iDir=%d\n",iDir);
        nSteps[iDir%2]--;
        iDir = (iDir+1)%4;
        nowStep=nSteps[iDir%2];
    }
    
    *returnSize=matrixSize*(*matrixColSize);
    return res;
}

/*
1.returnSize 需要赋返回的结构体长度
2.遇输入为空数组时需首先判断
3.使用dir数组控制方向，便于适应不同的方向要求
*/
