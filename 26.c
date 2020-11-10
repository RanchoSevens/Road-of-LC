/*
  1. 当仅当相邻数字不一致时更新i
*/


int removeDuplicates(int* nums, int numsSize){
    int i,now;
    for(i=1,now=i;now<numsSize;++now)
        if(nums[i-1] < nums[now])
            nums[i++] = nums[now];
    return i;
}
