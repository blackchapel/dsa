#include <stdio.h>
#include <stdlib.h>

struct node {
    int size;
    int front;
    int rear;
    int *s;
};

void enqueue(struct node *p, int value);
int dequeue(struct node *p);
void display(struct node *p);

int main() {
    struct node queue;

    printf("Enter the size: ");
    scanf("%d", &queue.size);

    queue.front = -1;
    queue.rear = -1;
    queue.s = (int *) malloc(queue.size * sizeof(int));

    int n = 1, value = 0;

    while(n) {
        printf("1. Enqueue \n2. Dequeue \n3. Display \n0. Exit \n");
        scanf("%d", &n);

        if(n == 1) {
            printf("Enter element: ");
            scanf("%d", &value);
            enqueue(&queue, value);
        } else if(n == 2) {
            printf("Element: %d\n", dequeue(&queue));            
        } else if(n == 3) {
            display(&queue);
        }
    }

    return 0;
}

void enqueue(struct node *p, int value) {
    if(p->rear == p->size-1) {
        printf("Queue Full\n");
        return;
    } else if(p->front == -1 && p->rear == -1) {
        p->front = 0;
        p->rear = 0;
    } else {
        p->rear++;
    }
    p->s[p->rear] = value;
}

int dequeue(struct node *p) {
    int x = -1;

    if(p->front > p->rear || p->front == -1) {
        printf("Queue Empty\n");
    } else {
        x = p->s[p->front]; 
        p->front++;
        if(p->front > p->rear) {
            p->front = -1;
            p->rear = -1;
        }
    }
    return x;
}

void display(struct node *p) {
    if(p->front > p->rear || p->front == -1) {
        printf("Queue Empty\n");
    }

    int i = p->front;

    while(i <= p->rear) {
        printf("%d\t", p->s[i]);
        i++;
    }
    printf("\n");
}