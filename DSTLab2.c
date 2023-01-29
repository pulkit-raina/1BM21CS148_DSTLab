#include<stdio.h>
#include<ctype.h>
#include<string.h>

void infixToPostfix(char in[]);
int getPriority(char c);
void infixToPostfix(char in[]);


int main(){
    char in[100];
    int l;
    printf("Enter the infix expression: ");
    gets(in);
    l = strlen(in);
    in[l] = '\n';
    infixToPostfix(in);
    return 0;
}



int getPriority(char c){
    if(c == '*' || c == '/')
        return 9;
    else if(c == '+' || c == '-')
        return 8;
    else
        return -1;
}

void infixToPostfix(char in[]){
    char out[100];
    int stk[100];
    int i = 0, j = -1, top = -1;
    while(in[i] != '\n'){
        if(isalnum(in[i]))
            out[++j] = in[i];

        else if(in[i] == '(')
            stk[++top] = in[i];

        else if(in[i] == '+' || in[i] == '-' || in[i] == '*' ||
           in[i] == '/'){
            while(getPriority(in[i])<=getPriority(stk[top]))
                out[++j] = stk[top--];
            stk[++top] = in[i];
        }
        else if(in[i] == ')'){
            while(stk[top] != '('){
                out[++j] = stk[top--];
            }
            top--;
        }
        else{
            printf("INCORRECT EXPRESSION\n");
            return;
        }
        i++;
    }
    while(top!=-1)
        out[++j] = stk[top--];
    printf("%s", out);
}
