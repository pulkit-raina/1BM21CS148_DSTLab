#include<stdio.h>

typedef struct node{
    int val;
    struct node* rnext;
    struct node* lnext;
}node;

node* insertElement(node* root, int val);
void displayElements(node* root);
void preorderTraversal(node* root);
void postorderTraversal(node* root);
void inorderTraversal(node* root);

int main(){
        node* root;
        int choice;
        printf("Enter\n1.Enter element 2.Display elements of tree\n");
        printf("3.Preorder Traversal 4.Postorder traversal 5.Inorder Traversal 6. Exit: ");
        do{
            scanf("%d", &choice);
            switch(choice){
            case 1:
                root = insertElement(root, val);
                break;
            case 2:
                displayElements(root);
                break;
            case 3:
                preorderTraversal(root);
                break;
            case 4:
                postorderTraversal(root);
                break;
            case 5:
                inorderTraversal(root);
                break;
            }
        }while(choice!=6);
        return 0;
}

node* insertElement(node* root, int val){

}

void displayElements(node* root){

}

void preorderTraversal(node* root){

}

void postorderTraversal(node* root){

}

void inorderTraversal(node* root){

}
