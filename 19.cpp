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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode* p=head,*former;
        ListNode* headNode = new ListNode(-1);
        headNode->next=head;
        while(p){
            len++;
            p=p->next;
        }
        p=head; former=headNode;
        for(int i=0;i<len-n;++i){
            former=p;
            p=p->next;
        }
        former->next=p->next;
        return headNode->next;
    }
};
/*
1.建立一个头结点统一第一个结点与后续结点的运算
*/
