struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head==NULL)
        return head;
    int length=1;
    struct ListNode *temp=head,*temp2;

    while(temp->next!=NULL){
        temp=temp->next;
        length++;
    }
    int rotate = length-(k%length);
    if(rotate==0)
        return head;
    temp->next=head;
    temp=head;
    while(rotate!=1){
        rotate--;
        temp=temp->next;
    }
    temp2=temp->next;
    head=temp2;
    temp->next=NULL;

    return head;



}
