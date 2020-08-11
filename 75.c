void quickSort(int start,int end,int *nums);

void sortColors(int* nums, int numsSize){
    quickSort(0,numsSize-1,nums);
}

void quickSort(int start,int end,int* nums){
    if(start >= end) return;
    int i, j, arrBase;
    i = start;
    j = end;
    arrBase = nums[i];
    while(i<j){
        while(i < j && nums[j] > arrBase) j--;
        if(i < j){
            nums[i++] = nums[j];
        }
        while(i < j && nums[i] < arrBase) i++;
        if(i < j){
            nums[j--]=nums[i];
        }        
    }
    nums[i] = arrBase;
    quickSort(start, i-1, nums);
    quickSort(i+1, end, nums);
}
/*
1.熟悉快排过程
2.递归一定要有一个返回(边界条件)
3.快排是基于分治法，分而治之
参考：https://blog.csdn.net/morewindows/article/details/6684558
*/
