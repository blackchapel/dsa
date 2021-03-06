#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*first = NULL;
struct node *last = NULL; 

void create(int value);
void insertBefore(struct node *p, int pos, int value);
void insertAfter(struct node *p, int pos, int value);
void delete(struct node *p, int pos);
void display(struct node *p);

int main() {
    int n = 1, value = 0, pos = 0;

    while(n) {
        printf("1. Create \n2. Insert Before \n3. Insert After \n4. Delete \n5. Display \n0. Exit\n");
        scanf("%d", &n);

        if(n == 1) {
            printf("Element to be inserted: ");
            scanf("%d", &value);
            create(value);
        } else if(n == 2) {
            if(first == NULL) {
                printf("No Elements\n");
            } else {
                printf("Insert Before: ");
                scanf("%d", &pos);
                printf("Element to be inserted: ");
                scanf("%d", &value);
                insertBefore(first, pos, value);  
            }  
        } else if(n == 3) {
            if(first == NULL) {
                printf("No Elements\n");
            } else {
                printf("Insert After: ");
                scanf("%d", &pos);
                printf("Element to be inserted: ");
                scanf("%d", &value);
                insertAfter(first, pos, value);
            }
        } else if(n == 4) {
            if(first == NULL) {
                printf("No Elements\n");
            } else {
                printf("Element to be deleted: ");
                scanf("%d", &pos);
                delete(first, pos);
            }
        } else if(n == 5) {
            if(first == NULL) {
                printf("No Elements\n");
            } else {
                display(first);
            }
        }
    }
    return 0;
}

void create(int value) {
    if(first == NULL) {
        first = (struct node *) malloc(sizeof(struct node));
        first->data = value;
        first->next = first;
        last = first;
    } else {
        struct node *t;
        t = (struct node *) malloc(sizeof(struct node));
        t->data = value;
        t->next = first;
        last->next = t;
        last = t;
    }
}   

void insertBefore(struct node *p, int pos, int value) {
    struct node *q = NULL;
    
    do {
        if(p->data == pos) {
            if(p == first) {
                struct node *t;
                t = (struct node *) malloc(sizeof(struct node));
                t->data = value;
                t->next = first;
                last->next = t;
                last = t;
            } else {
                struct node *t;
                t = (struct node *) malloc(sizeof(struct node));
                t->data = value;
                t->next = q->next;
                q->next = t;
            } 
            return;
        } 
        q = p;
        p = p->next;
    } while(p != first);

    printf("Invald Argument\n");
}

void insertAfter(struct node *p, int pos, int value) {
    do {
        if(p->data == pos) {
            if(p == last) {
                struct node *t;
                t = (struct node *) malloc(sizeof(struct node));
                t->data = value;
                t->next = p->next;
                p->next = t;
                last = t;
            } else {
                struct node *t;
                t = (struct node *) malloc(sizeof(struct node));
                t->data = value;
                t->next = p->next;
                p->next = t;
            }
            return;
        }
        p = p->next;
    } while(p != first);

    printf("Invald Argument\n");
}

void delete(struct node *p, int pos) {
    struct node *q = NULL;

    do {
        if(p->data == pos) {
            if(p == first && p->next == first) {
                free(first);
                first = NULL;
            } else if(p == first) {
                last->next = p->next;
                free(first);
                first = last->next;
            } else {
                q->next = p->next;
                free(p);
            }
            return;
        }
        q = p;
        p = p->next;
    } while(p != first);

    printf("Invalid Argument\n");
}

void display(struct node *p) {
    do {
        printf("%d\t", p->data);
        p = p->next;
    } while(p != first);

    printf("\n");
}