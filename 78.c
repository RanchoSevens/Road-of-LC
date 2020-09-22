// nums[c], arr_t[ind]
// n代表当前要形成的数组长度(由1开始，直到numsSize)

int dfs(int *nums, int c, int numsSize, int arr_t[], \
        int ind, int n, int **arr, int *returnSize, int **returnColumnSizes) 
{
    if (ind == n) 
    {
        arr[*returnSize] = (int *)malloc(sizeof(int) * n);  // 当前形成的子集长度为 n
        for (int i = 0; i < n; i++)
        {
            arr[*returnSize][i] = arr_t[i];
        }
        (*returnColumnSizes)[*returnSize] = n;
        (*returnSize)++;
        
        for(int i = 1; i <= n; i++)
        {
            if (nums[numsSize - i] != arr_t[n - i]) return 0; // 后n位每位比较，若不等返回0
        }
        if (n == numsSize) return 0; // 若全相等且n到达最大，返回0
        return 1; // 全相等而n未至最大，说明该个数的子集已遍历完毕，返回1
    }
    for (int i = c; i < numsSize; i++) 
    {
        arr_t[ind] = nums[i];
        int flag = dfs(nums, i + 1, numsSize, arr_t, ind + 1, n, \
                       arr, returnSize, returnColumnSizes);
        printf("flag = %d\n", flag);
        if (flag == 1)
        {
            n++;
            i = -1;
            ind = 0;
        }
    }
    return 0;
}

int ** subsets(int * nums, int numsSize, int * returnSize, int ** returnColumnSizes)
{
    long int len = 1;
    int count = 0;
    while (count < numsSize) 
    {
        len *= 2;
        count++;
    }// len 子集数量
    

    //  int ** arr 子集结果
    int **arr = (int **)malloc(sizeof(int *) * len);
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * len);
    // returnColumnSizes[i] 每个子集的长度
    
    int arr_t[numsSize];
    *returnSize = 0;
    arr[*returnSize] = (int *)malloc(sizeof(int) * 1);
    (*returnColumnSizes)[*returnSize] = 0;
    (*returnSize)++;
    
    printf("numsSize = %d\tcount = %d\tlen = %d\n",numsSize,count,len);
    
    dfs(nums, 0, numsSize, arr_t, 0, 1, arr, returnSize, returnColumnSizes);
    return arr;
}
