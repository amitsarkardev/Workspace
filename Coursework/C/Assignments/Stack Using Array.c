#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

//PUSH operation of STACK
void push(){
    int val;
    if(top == MAX-1){
        printf("Stack Overflow!\n");
    }else{
        printf("Enter the element to push: ");
        scanf("%d", &val);
        stack[++top]=val;
        printf("Pushed %d onto the stack.\n",val);
    }
}

//Pop operation of stack
void pop(){
    if (top == -1){
        printf("Stack Underflow!\n");
    }else{
        printf("Popped element: %d \n",stack[top--]);
    }
}

//Display Stack
void display(){
    if(top == -1){
        printf("The stack is empty.\n");}
        else{
        printf("Stack elements (Top to Bottom): \n");
        for(int i=top;i>=0;i--){
            printf("%d \n", stack[i]);
        }
    }
}

//Menu
int main(){
    int choice;
    while(1){
        printf("\n Stack Using Array \n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        if(scanf("%d",&choice)!=1)break;

        switch(choice){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid Choice\n");
        }
    }
    return 0;
}