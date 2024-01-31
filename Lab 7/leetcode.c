/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void append(struct ListNode **head, int val){
    struct ListNode* new=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* prev=*head;
    new->val=val;
    new->next=NULL;
    if(*head==NULL)
        *head=new;
    
    else{
        while(prev->next!=NULL)
            prev=prev->next;
        prev->next=new;
    }
}
 
int length(struct ListNode *head){
    struct ListNode *prev=head;
    int len=0;
    while(prev!=NULL){
        prev=prev->next;
        len++;
    }
    return len;
}

struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    struct ListNode** heads=(struct ListNode**)malloc(sizeof(struct ListNode*)*k);
    int len=length(head);
    struct ListNode* prev=head;
    for(int i=0;i<k;i++){
        struct ListNode* nhead=NULL;
        heads[i]=nhead;
    }

    int common=len/k;
    int extra=len%k;

    int iter;
    int i=0;
    while(prev!=NULL){
        for(int j=0;j<common+((extra>0)?1:0);j++){
            append(&heads[i],prev->val);
            prev=prev->next;
        }
        i++;
        extra--;
    }
    *returnSize=k;
    return heads;
}
