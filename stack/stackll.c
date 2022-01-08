#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*top = NULL;
struct node *last = NULL;
void push(int value);
int pop();
int peek(struct node *p, int pos);

int main() {
    int n = 1, value = 0, pos = 0;

    while(n != 0) {
        printf("1. Push \n2. Pop \n3. Peek \n0. Exit\n");
        scanf("%d", &n);

        if(n == 1) {
            printf("Enter the value: ");
            scanf("%d", &value);
            push(value);
        } else if(n == 2) {
            printf("%d\n", pop());
        } else if(n == 3) {
            printf("Enter the position: ");
            scanf("%d", &pos);
            printf("%d\n", peek(top, pos));
        }
    }

    return 0;
}

void push(int value) {
    struct node *t;
    t = (struct node *) malloc(sizeof(struct node));
    
    if(t == NULL) {
        printf("Stack Overflow\n");
    } else {
        t->data = value;
        t->next = top;
        top = t;
    }
}

int pop() {
    int x = -1;

    if(top == NULL) {
        printf("Stack Underflow\n");
    } else {
        struct node *t;
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }

    return x;
}

int peek(struct node *p, int pos) {
    int x = -1;

    if(top == NULL) {
        printf("Stack Underflow\n");
    } else {
        for(int i = 0; i < pos - 1 && p != NULL; i++) {
            p = p->next;
        }

        if(p == NULL) {
            printf("Invalid Position\n");
        } else {
            x = p->data;
        }
    }

    return x;
}