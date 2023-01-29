#include<stdio.h>

typedef struct nd{
    int data;
    struct nd* next;
}node;

node* createList(node* head, int n);
node* deleteFirst(node* head);
node* deleteLast(node* head);
node* deleteSpecific(node* head, int n);
void display(node* head);

int main(){
    int choice, n;
    node* head = NULL;
    printf("Enter\n1. Create List of n nodes\n2. Delete from front\n3. Delete from end\n");
    printf("4. Delete specific data\n5. Display List\n6. Exit: ");
    while(1){
        scanf("%d", &choice);
        switch(choice){
        case 1:
            printf("Enter number of nodes to create: ");
            scanf("%d", &n);
            head = createList(head, n);
            break;
        case 2:
            head = deleteFirst(head);
            break;
        case 3:
            head = deleteLast(head);
            break;
        case 4:
            printf("Enter data to delete: ");
            scanf("%d", &n);
            head = deleteSpecific(head, n);
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


node* deleteFirst(node* head){
    node* temp = head;
    if(head == NULL)
        printf("EMPTY LIST\n");
    else{
        head = head->next;
        free(temp);
    }
    return head;
}

node* deleteLast(node* head){
    node* temp = head;
    node* ptr;
    if(head == NULL){
        printf("EMPTY LIST\n");
        return head;
    }
    else if(head->next == NULL){
        head = NULL;
        free(temp);
        return head;
    }
    else{
        while(temp->next->next!=NULL)
            temp = temp->next;
       ptr = temp->next;
       temp->next = NULL;
       free(ptr);
    }
    return head;
}

node* deleteSpecific(node* head, int val){
    node* temp = head;
    node* ptr = head;
    if(head == NULL){
        printf("EMPTY LIST\n");
        return head;
    }
    if(head->next = NULL){
        head = NULL;
        free(temp);
        return head;
    }
    while(temp->data != val && temp->next != NULL)
        temp = temp->next;
    if(temp->data == val){
        ptr = head;
        while(ptr->next!=temp)
            ptr = ptr->next;
        ptr->next = temp->next;
        free(temp);
        return head;
    }
    else{
        printf("NO SUCH ELEMENT\n");
        return head;
    }
}

void display(node* head){
    node* temp = head;
    if(head == NULL){
        printf("EMPTY LIST!\n");
        return;
    }
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
