/*
1.i为结果下标，j为当前数组下标，n_num为当前处理数字，n_len为数字个数
2.数量超过2，则i不增;不超过2，i增加，并用n_num更新nums[i]
3.n_num更新，则n_len、nums[i]同时更新
*/

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
