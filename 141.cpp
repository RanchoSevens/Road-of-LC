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
    bool hasCycle(ListNode *head) {
        bool result = false;
        while(head&&head->val!=INT_MIN){
            head->val=INT_MIN;
            if(head->next&&head->next->val==INT_MIN){
                result=true;
                break;
            }
            head=head->next;
        }
        return result;
    }
};
