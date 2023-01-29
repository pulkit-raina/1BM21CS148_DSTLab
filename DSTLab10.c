#include<stdio.h>

typedef struct node{
    int data;
    struct node* rnext;
    struct node* lnext;
}node;

node* insertElement(node* root, int val);
void displayElements(node* root);
void preorderTraversal(node* root);
void postorderTraversal(node* root);
void inorderTraversal(node* root);

int main(){
        node* root = NULL;
        int choice, val;
        printf("Enter\n1.Enter element 2.Display elements of tree\n");
        printf("3.Preorder Traversal 4.Postorder traversal 5.Inorder Traversal 6. Exit: ");
        do{
            scanf("%d", &choice);
            switch(choice){
            case 1:
                printf("Enter data to input: ");
                scanf("%d", &val);
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
    node *ptr, *nodeptr, *parentptr;
    ptr = (node*)malloc(sizeof(node));
    ptr->data = val;
    ptr->lnext = NULL;
    ptr->rnext = NULL;
    if(root == NULL){
        root = ptr;
    }
    else{
        nodeptr = root;
        while(nodeptr!=NULL){
            parentptr = nodeptr;
            if(val<nodeptr->data){
                nodeptr = nodeptr->lnext;
            }
            else
                nodeptr = nodeptr->rnext;
        }
        if(parentptr->data > val)
            parentptr->lnext = ptr;
        else
            parentptr->rnext = ptr;
    }
    return root;
}

void displayElements(node* root){
    preorderTraversal(root);
}

void preorderTraversal(node* root){             //root first, then left subtree & then right subtree
    if(root!=NULL){
        printf("%d ", root->data);
        preorderTraversal(root->lnext);
        preorderTraversal(root->rnext);
    }
}

void postorderTraversal(node* root){           //first left subtree, then right and then root
    if(root!=NULL){
        postorderTraversal(root->lnext);
        postorderTraversal(root->rnext);
        printf("%d ", root->data);
    }
}

void inorderTraversal(node* root){             //ascending order
    if(root!=NULL){
        inorderTraversal(root->lnext);
        printf("%d ", root->data);
        inorderTraversal(root->rnext);
    }
}
