class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *first = new ListNode(-1), *last;
        first->next = head;
        if (k <= 1) return head;

        ListNode *p[k+1];
        p[0]=first;
        int len = 0;
        while (p[0]->next != NULL) {
            len++;
            p[0] = p[0]->next;
        }

        if (len < k) return head;

        p[0] = first;
        int times = len / k;
        while (times--) {
            for (int i = 1; i < k+1; ++i) {
                p[i] = p[i-1]->next;
            }
            last = p[k]->next;
            // cout<<"last="<<last->val<<endl;
            for (int i = k; i > 0; --i) {
                p[0]->next = p[i];
                p[0] = p[0]->next;
            }
            p[0]->next=last;
        }
        return first->next;
    }
};
/*
1.用头结点来统一操作
2.处理好指针
*/
