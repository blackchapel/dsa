#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*front = NULL, *rear = NULL;

void enqueue(int value);
int dequeue();
void display(struct node *p);

int main() {
    int n = 1, value = 0;

    while(n != 0) {
        printf("1. Enqueue \n2. Dequeue \n3. Display \n0. Exit \n");
        scanf("%d", &n);

        if(n == 1) {
            printf("Enter the element: ");
            scanf("%d", &value);
            enqueue(value);
        } else if(n == 2) {
            printf("Element: %d\n", dequeue());
        } else if(n == 3) {
            display(front);
        }
    }

    return 0;
}

void enqueue(int value) {
    struct node *t; 
    t = (struct node *) malloc(sizeof(struct node));

    if(t == NULL) {
        printf("Queue Full\n");
    } else {
        t->data = value;
        t->next = NULL;

        if(front == NULL) {
            front = t;
            rear = t;
        } else {
            rear->next = t;
            rear = t;
        }
    } 
}

int dequeue() {
    struct node *p;
    int x = -1;

    if(front == NULL) {
        printf("Oueue Empty\n");
    } else {
        p = front;
        x = front->data;
        front = front->next;
        free(p);
    }
    return x;
}

void display(struct node *p) {
    if(p == NULL) {
        printf("Queue Empty\n");
    } else {
        while(p != NULL) {
            printf("%d\t", p->data);
            p = p->next;
        }
        printf("\n");
    }
}