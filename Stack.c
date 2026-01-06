#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* top = NULL;// Initialize top to NULL for an empty stack

//Function to check if the stack is empty
int isEmpty(){
    return top == NULL;
}

//Function to add an element to the stack
void push(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));//Dynamically allocate memory
    if(newNode == NULL){
        printf("Memory Overflow! Stack is full.\n");//Handle memory allocation
        return;
    }
newNode->data = data;
newNode->next = top;// Link the new node to the previous top
top = newNode; //update top to the new node 
printf("Pushed %d onto the stack\n",data);
}
//function to remove an element from the stack
int pop(){
    if (isEmpty()){
        printf("Stack Underflow! Cannot pop from an empty stack\n");
        return -1;
    }else{
        Node* temp = top;
        int data = temp->data;
        top = top->next;
        free(temp);
        printf("Popped %d from the stack\n",data);
        return data;
    }
}
//Function to peek at the top element
int peek(){
    if (isEmpty()){
        printf("Stack is empty!\n");
        return -1;
    }else{
        return top->data;
    }
}

// main function to demonstrate stack operations
int main(){
push(10);
push(20);
push(30);

printf("Top element is %d\n", peek());

pop();
pop();
pop();
pop(); // Attempt to pop from  an empty stack

return 0;
}
