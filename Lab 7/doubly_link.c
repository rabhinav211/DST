#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node* head = NULL;
int count = 0;

void insert(int data, int position) {
    if (position == 0) {
        Node* newNode = malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL) head->prev = newNode;
        head = newNode;
        count++;
        return;
    } else if (position == count) {
        Node* newNode = malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        count++;
        return;
    } else if (position > count || position < 0) {
        printf("Unable to insert at the given position\n");
        return;
    } else {
        Node* temp = head;
        for (int i = 0; i < position - 1; i++)
            temp = temp->next;
        Node* newNode = malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        count++;
        return;
    }
}

void delete(int element) {
    int position = 0;
    Node* temp = head;
    if (head == NULL) {
        printf("List is empty, cannot delete\n");
        return;
    }
    for (; position < count; temp = temp->next, position++)
        if (temp->data == element) break;
    if (temp == NULL) {
        printf("Element does not exist in the list\n");
        return;
    }
    if (position == 0) {
        Node* temp = head;
        temp = temp->next;
        temp->prev = NULL;
        free(head);
        head = temp;
        count--;
        return;
    } else if (position == count - 1) {
        Node* temp = head;
        for (int i = 1; i < count - 1; i++)
            temp = temp->next;
        Node* temp1 = temp->next;
        temp->next = NULL;
        free(temp1);
        count--;
        return;
    } else if (position > count || position < 0) {
        printf("Unable to delete at the given position\n");
        return;
    } else {
        Node* temp = head;
        for (int i = 0; i < position; i++)
            temp = temp->next;
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        free(temp);
        count--;
        return;
    }
}

void display() {
    Node* temp = head;
    printf("Linked List: ");
    while (temp->next != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
    printf("\n");
}

int main() {
    int data, choice, pos;
    printf("1. Insert\n2. Delete\n3. Exit\nChoice: ");
    scanf("%d", &choice);
    while (choice != 3) {
        if (choice == 1) {
            printf("Enter data and position: ");
            scanf("%d%d", &data, &pos);
            insert(data, pos);
            printf("Count: %d\n", count);
        } else if (choice == 2) {
            printf("Enter element: ");
            scanf("%d", &pos);
            delete(pos);
            printf("Count: %d\n", count);
        }
        display();
        printf("Enter choice: ");
        scanf("%d", &choice);
    }

    return 0;
}
