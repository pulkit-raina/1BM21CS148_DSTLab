#include <stdio.h>

int isFull(int front, int rear, int n);
int isEmpty(int front);
void enQueue(int items[], int *front, int *rear, int n);
int deQueue(int items[], int *front, int *rear, int n);
void display(int items[], int *front, int *rear, int n);


int main()
{
    int items[100], front = -1, rear = -1, n, choice;
    printf("Enter size of queue(max is 100): ");
    scanf("%d",&n);
    printf("Enter your choice:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit:\n");
    while(1)
    {
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                enQueue(items, &front, &rear, n);
                break;
            case 2:
                deQueue(items, &front, &rear, n);
                break;
            case 3:
                display(items, &front, &rear, n);
                break;
            case 4:
                return 0;
            default:
                printf("Incorrect Choice! Enter again:\n");
                break;
        }
    }
    return 0;
}

int isFull(int front, int rear, int n)
{
    if ((front == rear + 1) || (front == 0 && rear == n - 1))
        return 1;
    return 0;
}

int isEmpty(int front)
{
    if (front == -1)
        return 1;
    return 0;
}

void enQueue(int items[], int *front, int *rear, int n)
{
    int element;
    if (isFull(*front, *rear, n))
        printf("Queue is full!! \n");
    else
    {
        printf("Enter element to enQueue: ");
        scanf("%d",&element);
        if (*front == -1)
            *front = 0;
        *rear = (*rear + 1) % n;
        items[*rear] = element;
        printf("Inserted -> %d\n", element);
    }
}

int deQueue(int items[], int *front, int *rear, int n)
{
    int element;
    if (isEmpty(*front))
    {
        printf("Queue is empty !! \n");
        return (-1);
    }
    else
    {
        element = items[*front];
        if (*front == *rear)
        {
            *front = -1;
            *rear = -1;
        }
        else
            *front = (*front + 1) % n;
        printf("Deleted element -> %d \n", element);
        return (element);
    }
}

void display(int items[], int *front, int *rear, int n)
{
    int i;
    if (isEmpty(*front))
        printf("Empty Queue\n");
    else
    {
        printf("Items -> ");
        printf("%d\t", items[*front]);
        for (i = *front+1; i != *rear; i = (i + 1) % n)
            printf("%d\t", items[i]);
        printf("%d\n",items[*rear]);
    }
}
