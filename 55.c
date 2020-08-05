bool canJump(int* nums, int numsSize){
    int i,reach;
    for(i=0,reach=i;i<numsSize&&i<=reach;i++){
        int k=reach>(i+nums[i])?reach:i+nums[i];
        if(reach<k) reach = k;
    }
    return i==numsSize;
}
/*
1.reach来控制能到达的最远位置(下标)
2.i由numsSize和reach两个共同控制，到达numsSize说明最后一个位置也可以走过去
*/
