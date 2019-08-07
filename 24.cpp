/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *p,*q,*former,*tmp;
        p=head;
        former=NULL;
        while(p!=NULL){
            if(p->next==NULL) return head;
            q=p->next;
            tmp=q->next;
            if(former!=NULL) former->next=q;
            else head=q;
            q->next=p;
            p->next=tmp;
            former=p;
            p=p->next;
        }
        return head;
    }
};
