/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){

    if(n==0){
        return NULL;
    }

    int **res = (int**)malloc(sizeof(int*) * n);  
    int *rcs = (int *)malloc(sizeof(int) * n);
    for(int i = 0;i < n; i++){
        res[i] = (int*)malloc(sizeof(int) * n); 
        rcs[i] = n;
    }
    
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int nSteps[2];
    nSteps[0]=n;
    nSteps[1]=n-1;
    int count = 0;
    int ns = n * n;
    int iDir=0;
    int im=0;
    int in=-1;
    while(count<ns){
        int nowDir=iDir%4;
        for(int i=0;i<nSteps[iDir%2];++i){
            im += dir[iDir][0];
            in += dir[iDir][1];
            res[im][in] = ++count;
        }
        nSteps[iDir%2]--;
        iDir=(iDir+1)%4;
    }

    *returnSize = n;
    *returnColumnSizes = rcs;
    return res;
}
/*
1.returnColumnSizes需每行设置
*/
