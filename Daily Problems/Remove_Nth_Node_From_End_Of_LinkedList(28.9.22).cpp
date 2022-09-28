//https://leetcode.com/problems/remove-nth-node-from-end-of-list/
class Solution {
public:
    int count = 1;
    int size(ListNode* head){
        int c=0;
        while(head){
            head=head->next;
            c++;
        }
        return c;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return NULL;
        int siz = size(head);
        if(siz-n == 0)
            return head->next;
        ListNode* temp1 =head, *temp2 = head->next;
        while(temp2){
        if(count == (siz-n)){
            temp1->next = temp2->next;
            return head;
        }
            count++;
            temp1=temp2;
            temp2=temp2->next;
        }
        return NULL;
    }
};