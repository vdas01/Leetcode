//https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/


class Solution {
public:
int count(ListNode *temp){
    int c=0;
    while(temp){
        temp=temp->next;
        c++;
    }
    return c;
}
ListNode* result(ListNode *head,int c){
        ListNode *temp = head;
        int count = 1;
        while(temp && count < c-1){
            temp=temp->next;
            count++;
        }
        return temp;
}
    ListNode* deleteMiddle(ListNode* head) {
        int c = count(head);
        if(c==1) return NULL;
        cout<<c<<" ";
        c=(c/2)+1;
        cout<<c<<"\n";
        ListNode* prev = result(head,c);
        ListNode* curr = prev->next;
        prev->next = curr->next;
        return head;
    }
};
