#include<stdio.h>
#include<stdlib.h>

void enquee(int queue[], int *front, int *rear, int n);
void dequee(int queue[], int *front, int *rear);
void display(int queue[], int *front, int *rear);

int main(){
    int queue[100], front = -1, rear = -1;
    int n,value,choice;
    printf("Enter length of queue(MAX 100): ");
    scanf("%d", &n);
    printf("Choose : \n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
    while(1){
        scanf("%d",&choice);
        switch(choice){
            case 1:
                enquee(queue, &front, &rear, n);
                break;
            case 2:
                dequee(queue, &front, &rear);
                break;
            case 3:
                display(queue, &front, &rear);
                break;
            case 4:
                exit(0);
            default:
                printf("INCORRECT INPUT TRY AGAIN");

        }
    }
}


void enquee(int queue[], int *front, int *rear, int n){
    int value;
    if(*rear==n-1)
        printf("OVER FLOW\n");
    else{
        printf("Enter value to be inserted: ");
        scanf("%d", &value);
        if (*front==-1 && *rear==-1)
            *front=0;
        queue[++(*rear)]=value;
    }
}

void dequee(int queue[], int *front, int *rear){
    if(*front==-1||*front>*rear)
        printf("UNDER FLOW\n");

    else{
        printf("value deleted : %d\n",queue[*front]);
        (*front)++;
    }
}

void display(int queue[], int *front, int *rear){
    int i;
    if(*front>*rear || *front==-1 && *rear == -1)
        printf("UNDERFLOW\n");
    else
        for(i=*front;i<=*rear;i++)
            printf("%d\n",queue[i]);
}
