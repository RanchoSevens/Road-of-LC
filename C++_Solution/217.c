/*
1.创建struct结构体soldier作为结点，army作为链表
2.使用哈希函数将值定位到某个链下，在该链中顺序搜索
*/
struct soldier
{
    int val;
    struct soldier * next;
};

struct army
{
    int size;
    struct soldier ** table;
};

void armInit(struct army * one, int num)
{
    one->size = num;
    one->table = (struct soldier *)malloc(num * sizeof(struct soldier *));
    memset(one->table, 0, num * sizeof(struct soldier *));
}

bool addValue(struct army * one, int val)
{
    int pos = val % one->size;
    if(pos < 0) pos += one->size;
    struct soldier * ptr = one->table[pos];
    while(ptr)
    {
        if(val == ptr->val){
            return false;
        }
        ptr = ptr->next;
    }
    ptr = malloc(sizeof(struct soldier));
    ptr->val = val;
    ptr->next = one->table[pos];
    one->table[pos] = ptr;
    return true;
}

void release(struct army * one)
{
    int num = one->size;
    int i;
    struct soldier * ptr, * tmp;
    for(i=0;i<num;++i)
    {
        ptr = one->table[i];
        while(ptr)
        {
            tmp = ptr;
            ptr = ptr->next;
            free(tmp);
        }
    }
    free(one->table);
    one->table = NULL;
    one->size = 0;
}


bool containsDuplicate(int* nums, int numsSize){
    if(numsSize < 2) return false;
    struct army am;
    int i;
    armInit(&am, numsSize / 2);
    for(i=0; i<numsSize; ++i)
    {
        if(!addValue(&am, nums[i]))
        {
            release(&am);
            return true;
        }
    }
    release(&am);
    return false;
}

/*
1.使用qsort排序后顺序判断前后两元素是否相等，相等则返回
*/
static int cmp(const int *l,const int *r)
{
    return *l-*r;
}



bool containsDuplicate(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    int i;
    for(i=0;i<numsSize-1;++i)
    {
        if(nums[i] == nums[i+1]) return true;
    }
    return false;
}














