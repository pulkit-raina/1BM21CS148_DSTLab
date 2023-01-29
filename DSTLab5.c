#include <stdio.h>
#include <stdlib.h>


typedef struct nd {
    int data;
    struct node *next;
}node;

node* insertBeginning(node* head);
node* insertEnd(node* head);
node* insertMiddle(node* head, int val);

int main(){
    node* head = NULL;
    int choice, val;
    printf("Enter\n1. Insert Node at beginning\n2. Insert Node at end\n");
    printf("3. Insert Node after a value\n4. Display List\n5. Exit: ");
    while(1){
        scanf("%d", &choice);
        switch(choice){
            case 1:
                head = insertBeginning(head);
                break;
            case 2:
                head = insertEnd(head);
                break;
            case 3:
                printf("Enter val after which you insert node: ");
                scanf("%d", &val);
                head = insertMiddle(head, val);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                return 0;
            default:
                printf("INCORRECT VALUE!/n");
        }
    }
    return 0;
}


node* insertBeginning(node* head){
    int val;
    node* temp;
    if(head == NULL){
        printf("NEW LINKED LIST CREATED!\n");
        printf("Enter element to insert: ");
        scanf("%d", &val);
        head = (node*)malloc(sizeof(node));
        head->next = NULL;
        head->data = val;
    }
    else{
        printf("Enter element to insert: ");
        scanf("%d", &val);
        temp = (node*)malloc(sizeof(node));
        temp->next = head;
        temp->data = val;
        head = temp;
    }
    return head;
}


node* insertEnd(node* head){
    node* temp = head;
    node* ptr;
    int val;
    while(temp->next!=NULL)
        temp = temp->next;
    ptr = (node*)malloc(sizeof(node));
    printf("Enter val to insert: ");
    scanf("%d", &val);
    ptr->data = val;
    ptr->next = NULL;
    temp->next = ptr;
    return head;
}

node* insertMiddle(node* head, int n){
    node* temp = head;
    node* ptr;
    int val;
    while(temp->data != n && temp->next != NULL)
        temp = temp->next;
    if(temp->data == n){
        printf("Enter val to insert: ");
        scanf("%d", &val);
        ptr = (node*)malloc(sizeof(node));
        ptr->next = temp->next;
        ptr->data = val;
        temp->next = ptr;
    }
    else
        printf("Value NOT Found in List!\n");
    return head;
}

void displayList(node* head){
    node* temp = head;
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
