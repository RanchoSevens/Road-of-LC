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


//solution不改变链表本身的解法
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode walker = head;
        ListNode runner = head;
        while(runner!=null && runner.next!=null) {
            walker = walker.next;
            runner = runner.next.next;
            if(walker==runner) return true;
        }
        return false;
    }
}

