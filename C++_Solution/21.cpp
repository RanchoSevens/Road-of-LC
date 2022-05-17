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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* firstNode = new ListNode(INT_MIN);//头结点
        ListNode* p = firstNode;
        while(l1&&l2){
            if(l1->val<l2->val){
                p->next=l1;
                p=p->next;
                l1=l1->next;
            }else{
                p->next=l2;
                p=p->next;
                l2=l2->next;
            }
        }
        if(l1) p->next=l1;
        else if(l2) p->next=l2;
        return firstNode->next;
    }
};
/*
1.加一个头结点使操作统一
*/
