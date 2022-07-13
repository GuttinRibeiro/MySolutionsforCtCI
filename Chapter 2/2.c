#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct linkedList {
    Node *header;
} LinkedList;

LinkedList *createLinkedList() {
    LinkedList *l = (LinkedList *) malloc(sizeof(LinkedList));
    if (l == NULL) {
        return NULL;
    }

    l->header = NULL;
    return l;    
}

int insertElement(LinkedList *l, int elem) {
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

void printLinkedList(LinkedList *l) {
    if (l == NULL) {
        return;
    }

    Node *aux = l->header;
    while (aux != NULL) {
        printf("%d ", aux->value);
        aux = aux->next;
    }

    printf("\n");
}

Node * kthToLast(LinkedList *l, int k) {
    if (l == NULL || k < 0) {
        return NULL;
    }

    Node *front = l->header;
    int i = 1;
    while (front != NULL && i < k) {
        front = front->next;
        i = i + 1;
    }

    if (front == NULL) {
        return NULL;
    }

    Node *back = l->header;
    while (front->next != NULL) {
        front = front->next;
        back = back->next;
    }

    return back;
} 

void destroyLinkedList(LinkedList *l) {
    if (l == NULL) {
        return;
    }

    Node *p = l->header;
    while (p != NULL) {
        l->header = p->next;
        free(p);
        p = l->header;
    }

    free(l);
}

int main() {
    printf("Insert the number of elements to be stored in your linked list: \n");
    int n;
    scanf("%d", &n);

    LinkedList *l = createLinkedList();
    printf("Now insert each element in a unique line: \n");
    int elem;
    for(int i=0; i<n; i++) {
        scanf(" %d", &elem);
        insertElement(l, elem);
    }

    printf("Now insert k: \n");
    int k;
    scanf(" %d", &k);

    printLinkedList(l);
    Node *reference = kthToLast(l, k);
    if (reference == NULL) {
        printf("k is invalid\n");
    }
    else {
        while (reference != NULL) {
            printf("%d ", reference->value);
            reference = reference->next;
        }
        printf("\n");
    }
    // printLinkedList(l);
    destroyLinkedList(l);
    return 0;
}