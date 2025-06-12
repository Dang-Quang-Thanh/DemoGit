#include <stdio.h>
#include <stdlib.h>

 struct node {
    int val;
    struct node* next;
}; typedef struct node node;

node *head;

node *createnode(int value){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->val = value;
    newnode->next = NULL;
    return newnode;
}

void Insert(int value){
    node *newnode = createnode(value);
    newnode->next = head;
    head = newnode;
}

void printlist(){
    node *print = head;
    while(print != NULL){
        printf("%d ", print->val);
        print = print->next;
    }
    printf("NULL\n");
}

int main(){
    head = NULL;
    for(int i = 1; i <= 5; i++){
        Insert(i);
    }
    printlist();
}

