int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    if(obstacleGrid[0][0]==1) return 0;
    int m=obstacleGridSize;
    int n=*obstacleGridColSize;

    int i,j,flag;
    
    flag=1;
    for(j=0;j<n;++j){
        if(flag&&(obstacleGrid[0][j]==0)) obstacleGrid[0][j]=1;
        else{
            flag=0;
            obstacleGrid[0][j]=0;
        }
    }
    flag=1;
    for(i=1;i<m;++i){
        if(flag&&(obstacleGrid[i][0]==0)) obstacleGrid[i][0]=1;
        else{
            flag=0;
            obstacleGrid[i][0]=0;
        }
    }

    for(i=1;i<m;++i){
        for(j=1;j<n;++j){
            if(obstacleGrid[i][j]==0) obstacleGrid[i][j] = obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
            else obstacleGrid[i][j]=0;
        }
    }
    return obstacleGrid[m-1][n-1];
}
/*
1.常规dp，第一行和第一列特殊处理
2.坑点：
  a)[0][j]特殊处理后应从[i][1]开始
  b)==的优先级高于&&
*/
