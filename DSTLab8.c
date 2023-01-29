#include<stdio.h>

typedef struct nd{
    int data;
    struct nd* next;
}node;

node* enterElementStack(node* head, int n);
node* popElement(node* head);
void displayStack(node* head);
node* enterElementQueue(node* head, int n);
node* removeElement(node* head);
void displayQueue(node* head);


int main(){
    char c;
    printf("Enter you want stack(s) of queue(q): ");
    scanf("%c", &c);
    if(c == 'q')
        queue();
    else if(c == 's')
        stack();
    else{
        printf("INCORRECT CHOICE!\n");
        return 0;
    }
}


void queue(){
    node* head = NULL;
    int choice;
    int n;
    printf("Enter choice\n1. Enter Element\n2. Remove Element\n3. Display Queue\n4. Exit\n");
    do{
        scanf("%d", &choice);
        switch(choice){
        case 1:
            printf("Enter element: ");
            scanf("%d", &n);
            head = enterElementQueue(head, n);
            break;
        case 2:
            head = removeElement(head);
            break;
        case 3:
            displayQueue(head);
            break;
        default:
            printf("Thanks! Try again!");
        }
    }while(choice!=4);
    return 0;
}


void stack(){
    node* head = NULL;
    int choice;
    int n;
    printf("Enter choice\n1. Enter Element\n2. Pop Element\n3. Display Stack\n4. Exit\n");
    do{
        scanf("%d", &choice);
        switch(choice){
        case 1:
            printf("Enter element to enter: ");
            scanf("%d", &n);
            head = enterElementStack(head, n);
            break;
        case 2:
            head = popElement(head);
            break;
        case 3:
            displayStack(head);
            break;
        default:
            printf("Thank you, please Try Again!");
        }
    }while(choice!=4);
}

node* enterElementStack(node* head, int n){
    node* ptr;
    node* temp;
    if(head == NULL){
        printf("Stack Initialised\n");
        ptr = (node*)malloc(sizeof(node));
        head = ptr;
        head->data = n;
        head->next = NULL;
    }
    else{
        ptr = head;
        while(ptr->next!=NULL)
            ptr = ptr->next;
        temp = (node*)malloc(sizeof(node));
        ptr->next = temp;
        temp->data = n;
        temp->next = NULL;
    }
    return head;
}

node* popElement(node* head){
    node* temp1 = head;
    node* temp2 = head;
    if(head==NULL){
        printf("UNDERFLOW\n");
        return head;
    }
    else{
        while(temp1->next!=NULL)
            temp1 = temp1->next;
        while(temp2->next!=temp1 && temp2!=temp1)
            temp2 = temp2->next;
        if(head->next == NULL)
            head = NULL;
        temp2->next = NULL;
        printf("Element popped is %d\n", temp1->data);
        free(temp1);
        return head;
    }
}

void displayStack(node* head){
    node* temp = head;
    if(head == NULL)
        printf("UNDERFLOW\n");
    else{
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

node* enterElementQueue(node* head, int n){
    node* temp = head;
    node* ptr;
    if(head == NULL){
        printf("QUEUE INITIALISED\n");
        ptr = (node*)malloc(sizeof(node));
        ptr->data = n;
        ptr->next = NULL;
        head = ptr;
    }
    else{
        while(temp->next!=NULL)
            temp = temp->next;
        ptr = (node*)malloc(sizeof(node));
        ptr->data = n;
        ptr->next = NULL;
        temp->next = ptr;
    }
    return head;
}

node* removeElement(node* head){
    node* temp1 = head;
    node* ptr;
    if(head == NULL){
        printf("UNDERFLOW\n");
        return head;
    }
    else{
        printf("Remove element is %d\n", head->data);
        head = head->next;
        free(temp1);
    }
    return head;
}

void displayQueue(node* head){
    node* temp = head;
    if(head == NULL){
        printf("UNDERFLOW\n");
    }
    else{
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
