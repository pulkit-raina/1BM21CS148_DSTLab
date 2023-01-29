#include<stdio.h>

typedef struct nd{
    int data;
    struct nd* next;
    struct nd* prev;
}node;

node* createList(node* head, int n);
node* insertLeft(node* head, int n);
node* deleteElement(node* head, int n);
void displayList(node* head);


int main(){
    int choice, n;
    node* head = NULL;

    printf("Enter\n1. Creating n nodes of double linked list\n");
    printf("2. Insert new node left of\n3. Delete specific node\n4. Display list\n5. Exit: ");
    while(1){
        scanf("%d", &choice);
        switch(choice){
        case 1:
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            head = createList(head, n);
            break;
        case 2:
            printf("Enter node left to which insert is to be done: ");
            scanf("%d", &n);
            head = insertLeft(head, n);
            break;
        case 3:
            printf("Enter node to delete: ");
            scanf("%d",&n);
            head = deleteElement(head, n);
            break;
        case 4:
            displayList(head);
            break;
        case 5:
            return 0;
        default:
            printf("INCORRECT VALUE!\n");
            break;
        }
    }
}

node* createList(node* head, int n){
    node* temp;
    node* ptr;
    int i, val;
    for(i = 0; i<n; i++){
        if(i==0){
            printf("NEW LIST CREATED!\n");
            printf("Enter element: ");
            scanf("%d", &val);
            temp = (node*)malloc(sizeof(node));
            temp->data = val;
            temp->next = NULL;
            temp->prev = NULL;
            head = temp;
        }
        else{
            ptr = head;
            printf("Enter element: ");
            scanf("%d", &val);
            while(ptr->next!=NULL)
                ptr = ptr->next;
            temp = (node*)malloc(sizeof(node));
            temp->data = val;
            temp->next = NULL;
            temp->prev = ptr;
            ptr->next = temp;
        }
    }
    return head;
}

node* insertLeft(node* head, int n){
    node* ptr;
    node* temp;
    int val;
    if(head == NULL){
        printf("Value doesn't exist!\n");
        return head;
    }
    else if(head->next == NULL && head->data == n){
        printf("Enter value to insert: ");
        scanf("%d", &val);
        temp = (node*)malloc(sizeof(node));
        temp->data = val;
        temp->next = head;
        temp->prev = NULL;
        head->prev = temp;
        head = temp;
        return head;
    }
    else{
        ptr = head;
        while(ptr->data!=n && ptr->next!=NULL)
            ptr = ptr->next;
        if(ptr->data == n){
            temp = (node*)malloc(sizeof(node));
            printf("Enter value to insert: ");
            scanf("%d", &val);
            if(ptr->prev == NULL){
                temp->next = head;
                temp->data = val;
                temp->prev = NULL;
                head->prev = temp;
                head = temp;
            }
            else{
                temp->data = val;
                temp->next = ptr;
                temp->prev = ptr->prev;
                ptr->prev->next = temp;
                ptr->prev = temp;
            }

        }
        else{
            printf("Data doesn't exist!\n");
        }
    }
    return head;
}


node* deleteElement(node* head, int n){
    node* temp;
    if(head == NULL)
        printf("EMPTY LIST!\n");
    else{
        temp = head;
        while(temp->next!=NULL && temp->data!=n)
            temp = temp->next;
        if(temp->data == n){
            if(temp->next == NULL && temp->prev == NULL){
                head = NULL;
                free(temp);
            }
            else if(temp->next == NULL){
                temp->prev->next = NULL;
                free(temp);
            }
            else if(temp->prev == NULL){
                temp->next->prev = NULL;
                head = temp->next;
                free(temp);
            }
            else{
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                free(temp);
            }
        }
        else
            printf("DATA DOESN'T EXIST!\n");
    }
    return head;
}


void displayList(node* head){
    node* temp;
    if(head == NULL)
        printf("EMPTY LIST!\n");
    else{
        temp = head;
        while(temp!=NULL){
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
