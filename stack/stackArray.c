#include <stdio.h>
#include <stdlib.h>

struct node {
    int size; 
    int top;
    int *s;
};

void push(struct node *p, int value);
int pop(struct node *p);
int peek(struct node *p, int pos);

int main() {
    struct node st;

    printf("Enter the size of the stack: ");
    scanf("%d", &st.size);

    st.top = -1;
    st.s = (int *) malloc(st.size * sizeof(int));

    int n = 1, value = 0, pos = 0;

    while (n != 0) {
        printf("1. Push \n2. Pop \n3. Peek \n0. Exit\n");
        scanf("%d", &n);

        if(n == 1) {
            printf("Enter the value: ");
            scanf("%d", &value);
            push(&st, value);
        } else if(n == 2) {
            printf("%d\n", pop(&st));
        } else if(n == 3) {
            printf("Enter the position: ");
            scanf("%d", &pos);
            printf("%d\n", peek(&st, pos));
        }
    }

    return 0;
}

void push(struct node *p, int value) {
    if(p->top >= p->size-1) {
        printf("Stack Overflow\n");
    } else {
        p->top++;
        p->s[p->top] = value;
    }
}

int pop(struct node *p) {
    int x = -1;

    if(p->top == -1) {
        printf("Stack Underflow\n");
    } else {
        x = p->s[p->top];
        p->top--;
    }

    return x;
}

int peek(struct node *p, int pos) {
    int x = -1;
    int index;

    if(p->top == -1) {
        printf("Stack Underflow\n");
    } else {
        index = (p->top) - pos + 1;
        if(index < 0) {
            printf("Invalid Position\n");
            return x;
        }
        x = p->s[index];
    }

    return x;
}