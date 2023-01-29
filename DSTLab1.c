#include<stdio.h>
#include<stdlib.h>

void push(int stk[], int n, int *top);
void pop(int stk[], int *top);
void display(int stk[], int *top);

int main(){
    int stk[100], top, n, ch;
    top = -1;
    printf("Enter the size of stack: ");
    scanf("%d",&n);
    printf("Enter your choice:\n1. Push into Stack\n2. Pop from Stack\n3. Display Stack\n4. Exit\n");
    while(1){
        scanf("%d",&ch);
        switch(ch){
            case 1: push(stk,n,&top);
                break;
            case 2: pop(stk, &top);
                break;
            case 3: display(stk, &top);
                break;
            case 4: return 0;
                break;
            default: printf("WRONG CHOICE\n");
                break;
        }
    }
}

void push(int stk[], int n, int *top){
    int x;
    if (*top!=n-1){
            printf("Enter the element to push in: ");
            scanf("%d",&x);
            stk[++(*top)] = x;
        }
    else
        printf("STACK OVERFLOW\n");
}

void pop(int stk[], int *top){
    if (*top<0)
        printf("STACK UNDERFLOW\n");
    else{
        printf("Popped element is %d\n", stk[*top]);
        (*top)--;
    }
}

void display(int stk[], int *top){
    int i;
    if(*top==-1)
        printf("STACK UNDERFLOW\n");
    else{
        printf("Stack is:\n");
        for(i=*top;i>-1;i--)
            printf("%d\n",stk[i]);
    }
}
