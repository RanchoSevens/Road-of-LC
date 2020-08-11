void quickSort(int start,int end,int *nums);
void swap(int* a,int *b);

void sortColors(int* nums, int numsSize){
    quickSort(0,numsSize-1,nums);
}

void quickSort(int start,int end,int* nums){
    if(start >= end) return;
    int arrBase = nums[start];
    int i,j;
    i = start;
    j = end;
    while(i<j){
        while(i < j && nums[j] > arrBase) j--;
        if(i < j){
            swap(&nums[i],&nums[j]);
            i++;
        }
        while(i < j && nums[i] < arrBase) i++;
        if(i < j){
            swap(&nums[i],&nums[j]);
            j--;
        }        
    }
    nums[i] = arrBase;
    quickSort(start, i-1, nums);
    quickSort(i+1, end, nums);
}
void swap(int *a,int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}
/*
1.熟悉快排过程
2.递归一定要有一个返回(边界条件)
3.快排是基于分治法，分而治之
*/
