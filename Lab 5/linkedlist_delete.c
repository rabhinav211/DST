#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void push(struct node** head, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void append(struct node** head, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = new_data;
    new_node->next = NULL;
    struct node* last = *head;

    if (*head == NULL)
        *head = new_node;
    else {
        while (last->next != NULL)
            last = last->next;

        last->next = new_node;
    }
}

void insertafterptr(struct node* prev, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = new_data;
    new_node->next = prev->next;
    prev->next = new_node;
}

void insertafterpos(int position, int data, struct node** head) {
    struct node* prev = *head;

    for (int i = 0; i < position-1; i++) {
        prev = prev->next;
        if (prev == NULL) {
            printf("Position greater than size\n");
            return;
        }
    }

    insertafterptr(prev, data);
}

void insertafterval(int value, int data, struct node** head) {
    struct node* prev = *head;

    while (prev->next != NULL) {
        if (prev->data == value) {
            insertafterptr(prev, data);
            return;
        }
        prev = prev->next;
    }
    printf("The value doesn't exist in the linked list\n");
}

void display(struct node* head) {
    if (head == NULL) {
        printf("Linked List empty.\n");
        return;
    }
    printf("Linked List:");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void del_head(struct node **head){
    if(*head==NULL){
        printf("List is empty\n");
        return;
    }
    struct node *temp=(*head)->next;
    free(*head);
    *head=temp;
}

void del_end(struct node *head){
    if(head==NULL){
        printf("List Empty\n");
        return;
    }
    struct node *last=head;

    struct node *prev;
    while(last->next!=NULL){
        prev=last;
        last=last->next;
    }
    free(last);
    prev->next=NULL;

}

void del_mid(struct node *target,struct node *head){
    struct node *temp=target->next;
    struct node *prev=head;
    while(prev->next!=target)
        prev=prev->next;
    free(target);
    prev->next=temp;
}

void del_val(int val,struct node **head){
    struct node *temp=*head;
    if(temp->data==val){
        del_head(head);
        return;
    }
    while(temp->next!=NULL){
        if(temp->data==val){
            del_mid(temp,*head);
            return;
        }
        temp=temp->next;
    }
    printf("This value does not exist in linked list\n");
}

void del_pos(int val,struct node *head){
    struct node *temp=head;
    for(int i=0;i<val-1;i++){
        temp=temp->next;
        if(temp==NULL){
            printf("Index is more than length of linked list\n");
            return;
        }
    }
    
    del_mid(temp,head);
}

int main() {
    struct node* head = NULL;
    int choice,val,pos,preval,choice2;
    int choice3;
    append(&head,1);
    append(&head,2);
    append(&head,3);
    append(&head,4);
    append(&head,5);
    while (1)
    {
        printf("------------------------------\n");
        printf("1.Insert\n2.Delete\n3.Display\nChoice:");
        scanf("%d",&choice);
        printf("------------------------------\n");
        switch (choice)
        {
            case 1:
                printf("Enter Value to insert:");
                scanf("%d",&val);
                printf("1.Insert at Head\n2.Insert at End\n3.Insert at middle\nChoice:");
                scanf("%d",&choice2);

                switch (choice2)
                {
                    case 1:
                        push(&head,val);
                        printf("%d inserted at head.\n",val);
                        display(head);
                        break;
                    
                    case 2:
                        append(&head,val);
                        printf("%d inserted at end.\n",val);
                        display(head);
                        break;
                    
                    case 3:
                        printf("1.Insert at index\n2.Insert after value\nChoice:");
                        scanf("%d",&choice3);
                        printf("-+-+-+-+-+-\n");
                        switch (choice3)
                        {
                            case 1:
                                printf("Enter the index:");
                                scanf("%d",&pos);

                                insertafterpos(pos,val,&head);
                                display(head);
                                printf("-+-+-+-+-+-\n");
                                break;
                            
                            case 2:
                                printf("Enter the Value:");
                                scanf("%d",&preval);
                                
                                insertafterval(preval,val,&head);
                                display(head);
                                break;

                            default:
                                break;

                        }
                    default:
                        break;
                }
                break;
            case 2:
                printf("1.Delete at head\n2.Delete at tail\n3.Delete in middle\nChoice:");
                scanf("%d",&choice);
                switch (choice)
                {
                case 1:
                    del_head(&head);
                    display(head);
                    break;
                case 2:
                    del_end(head);
                    display(head);
                    break;
                case 3:

                    printf("1.Delete a value\n2.Delete at index\nChoice:");
                    scanf("%d",&choice2);
                    switch (choice2)
                    {
                        case 1:
                            printf("Enter Value:");
                            scanf("%d",&val);
                            del_val(val,&head);
                            display(head);
                            break;
                        
                        case 2:
                            printf("Enter Index:");
                            scanf("%d",&pos);
                            del_pos(pos,head);
                            display(head);
                            break;
                    }
                }
                break;
            case 3:
                display(head);
                break;
        }
    }
    return 0;
}

