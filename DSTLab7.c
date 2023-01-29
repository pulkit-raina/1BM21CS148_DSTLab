#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

node* createList(node* head, int n);
node* sort(node* heada);
node* reverse(node* head);
node* concatanate(node* heada, node* headb);
void display(node* heada);

int main(){
    int choice, n;
    node* head = NULL;
    node* head2 = NULL;
    printf("Enter\n1. Create List of n nodes\n2. Sort the List\n3. Reverse the list\n");
    printf("4. Concatenate two lists\n5. Display List\n6. Exit: ");
    while(1){
        scanf("%d", &choice);
        switch(choice){
        case 1:
            printf("Enter number of nodes to create: ");
            scanf("%d", &n);
            head = createList(head, n);
            break;
        case 2:
            head = sort(head);
            break;
        case 3:
            head = reverse(head);
            break;
        case 4:
            printf("Enter number of data of list 2: ");
            scanf("%d", &n);
            head2 = createList(head2, n);
            head = concatanate(head, head2);
            break;
        case 5:
            display(head);
            break;
        case 6:
            return 0;
        default:
            printf("INCORRECT ENTRY!\n");
        }
    }
}

node* createList(node* head, int n){
    node* temp;
    node* ptr = head;
    int val;
    for(int i = 0; i<n; i++){
        temp = (node*)malloc(sizeof(node));
        if(i==0){
            printf("New Linked List created!\n");
            printf("Enter the data for first node: ");
            scanf("%d", &val);
            temp->data = val;
            temp->next = NULL;
            head = temp;
            printf("NODE 1 created\n");
        }
        else{
            ptr = head;
            while(ptr->next!=NULL)
                ptr = ptr->next;
            printf("Enter the data for node: ");
            scanf("%d", &val);
            temp->data = val;
            temp->next = NULL;
            ptr->next = temp;
        }
    }
    return head;
}


node* sort(node* heada){
    // node* prev = heada;
    node* temp1 = heada;
    int c;
    while(temp1->next != NULL){

        node* temp2 = temp1->next;
        while (temp2 != NULL){

            if(temp2->data > temp1->data){
                c = temp1->data;
                temp1->data = temp2->data;
                temp2->data = c;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1-> next;
    }
    display(heada);
    return heada;
}

node* reverse(node* head){

    node* prev = head;
    node* pres = prev->next;
    node* temp = pres;
    prev->next = NULL;

    while(temp->next!= NULL){
        temp = pres->next;
        pres->next = prev;
        prev = pres;
        pres = temp;

    }
    temp->next = prev;
    head = pres;

    display(head);
    return head;
}

node* concatanate(node* heada, node* headb){

    node* temp = heada;

    while(temp->next!= NULL){
        temp = temp-> next ;
    }
    temp->next = headb;
    display(heada);
    return heada;
}



void display(node* heada){
    node* temp = heada;
    while(temp!= NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
