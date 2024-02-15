#include<stdio.h>
#include<stdlib.h>

typedef struct bst{
    int val;
    struct bst *left;
    struct bst *right;
}node;

node *newNode(int val){
    node *newN=(node*)malloc(sizeof(node));

    newN->left=newN->right=NULL;
    newN->val=val;

    return newN;
}

void insert(node *root,node *temp){
    if(root->val>temp->val){
        if(root->left!=NULL)
            insert(root->left,temp);
        else
            root->left=temp;
    }

    if(root->val<temp->val){
        if(root->right!=NULL)
            insert(root->right,temp);
        else
            root->right=temp;
    }
}

void inorder(node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->val);
        inorder(root->right);
    }
}

void postorder(node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->val);
    }
}

void preorder(node *root){
    if(root!=NULL){
        printf("%d ",root->val);
        preorder(root->left);
        preorder(root->right);
    }

}

void main(){
    int choice,val;
    node *root=NULL,*temp;
    while(choice<3){
        printf("1.Insert\n2.Display\nChoice:");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert:");
            scanf("%d",&val);
            temp=newNode(val);
            if(root==NULL)
                root=temp;
            else
                insert(root,temp);
            break;
        case 2:
            printf("preorder: ");
            preorder(root);
            printf("\n");
            printf("postorder:");
            postorder(root);
            printf("\n");
            printf("inorder:");
            inorder(root);
            printf("\n");
            break;
        
        default:
            break;
        }
        printf("---------------\n");
    }
    
}
