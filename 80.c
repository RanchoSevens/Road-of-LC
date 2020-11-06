/*
1.i为结果下标，j为当前数组下标，n_num为当前处理数字，n_len为数字个数
2.数量超过2，则i不增;不超过2，i增加，并用n_num更新nums[i]
3.n_num更新，则n_len、nums[i]同时更新
*/
(80. Remove Duplicates from Sorted Array II)
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

int removeDuplicates(int* nums, int numsSize){
    if(numsSize == 0) return 0;
    int i,j,n_num,n_len;
    i=0;
    j=1;
    n_num = nums[0];
    n_len = 1;
    while(j<numsSize){
        if(nums[j] == n_num){
            n_len++;
            if(n_len<3){
                i++;
            }
            nums[i] = n_num;
        }else{
            n_num = nums[j];
            nums[++i] = n_num;
            n_len = 1;
        }
        j++;
    }
    return i+1;
}

/*
1.他山之石
2.不多于2个重复数字，则从下标为2开始遍历，i表示待更新的下标，now则为当前遍历到的下标
3.若 nums[now] > nums[i-2]，则说明now下标所代表的数应该被正确放置于i位置，无论i与now是否相等
*/
int removeDuplicates(int* nums, int numsSize){
    if(numsSize < 3) return numsSize;
    int i = 2;
    for (int now = i;now < numsSize;++now){
        if ( nums[now] > nums[i-2])
            nums[i++] = nums[now];
    }
    return i;
}
