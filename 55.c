bool canJump(int* nums, int numsSize){
    int i,reach;
    for(i=0,reach=i;i<numsSize&&i<=reach;i++){
        int k=reach>(i+nums[i])?reach:i+nums[i];
        if(reach<k) reach = k;
        if(reach>=numsSize-1) return true;
    }
    return false;
}
/*
1.reach来控制能到达的最远位置(下标)
2.当reach到达最后一个下标，返回true，否则false
*/
