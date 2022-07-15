#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    long value;
    struct node *next;
} Node;

typedef struct linkedList {
    Node *header;
} LinkedList;

typedef struct node_p {
    Node *value;
    struct node_p *next;
} NodeP;

typedef struct linkedListP {
    NodeP *header;
} LinkedListP;

LinkedList *createLinkedList() {
    LinkedList *l = (LinkedList *) malloc(sizeof(LinkedList));
    if (l == NULL) {
        return NULL;
    }

    l->header = NULL;
    return l;    
}

LinkedListP *createLinkedListP() {
    LinkedListP *l = (LinkedListP *) malloc(sizeof(LinkedListP));
    if (l == NULL) {
        return NULL;
    }

    l->header = NULL;
    return l;    
}

int insertElement(LinkedList *l, long elem) {
    if (l == NULL) {
        return 1;
    }

    Node *n = (Node *) malloc(sizeof(Node));
    if (n == NULL) {
        return 1;
    }

    n->next = NULL;
    n->value = elem;

    Node *p = l->header;
    if (p == NULL) {
        l->header = n;
    }
    else {
        while(p->next != NULL) {
            p = p->next;
        }

        p->next = n;
    }

    return 0;
}

int isInList(LinkedList *l, long elem) {
    if (l == NULL) {
        return 0;
    }

    Node *p = l->header;
    while (p != NULL) {
        if (p->value == elem) {
            return 1;
        }
        p = p->next;
    }

    return 0;
}

void printLinkedList(LinkedList *l) {
    if (l == NULL) {
        printf("Linked List is invalid\n");
        return;
    }

    Node *aux = l->header;
    while (aux != NULL) {
        printf("%ld->", aux->value);
        aux = aux->next;
    }

    printf("\n");
}

int detectLoop(LinkedList *l) {
    if (l == NULL) {
        return 0;
    }

    Node *p = l->header;
    if (p == NULL) {
        return 0;
    }

    LinkedList *visitedNodes = createLinkedList();
    if (visitedNodes == NULL) {
        printf("There is no memory available to run my algorithm\n");
        return -1;
    }

    while (p->next != NULL) {
        if (isInList(visitedNodes, (long)p)) {
            return 1;
        }
        insertElement(visitedNodes, (long)p);
        p = p->next;
    }

    return 0;
}

int main() {
    Node *n1 = (Node *)malloc(sizeof(Node));
    n1->value = 3;
    Node *n2= (Node *)malloc(sizeof(Node));
    n2->value = 1;
    Node *n3 = (Node *)malloc(sizeof(Node));
    n3->value = 5;
    Node *n4 = (Node *)malloc(sizeof(Node));
    n4->value = 9;
    Node *n5 = (Node *)malloc(sizeof(Node));
    n5->value = 7;
    Node *n6 = (Node *)malloc(sizeof(Node));
    n6->value = 2;
    Node *n7 = (Node *)malloc(sizeof(Node));
    n7->value = 1;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n3;

    LinkedList *l = createLinkedList();
    l->header = n1;
    printf("The Linked List provided has a loop: %d\n", detectLoop(l));
    
    n7->next = NULL;
    printf("The Linked List provided has a loop: %d\n", detectLoop(l));

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    free(n6);
    free(n7);
    return 0;
}