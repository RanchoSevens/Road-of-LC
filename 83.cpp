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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;
        ListNode *former = head,*p = head -> next;
        while(p){
            cout<<p->val<<endl;
            if(p->val == former->val){
                ListNode* temp = p;
                p = p -> next;
                former -> next = p;
            }else{
                former = p;
                p = p -> next;
            }
        }
        return head;
    }
};
