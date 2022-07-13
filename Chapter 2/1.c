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

void removeDuplicates(LinkedList *l) {
    if (l == NULL) {
        return;
    }

    Node *aux = l->header;
    if (aux == NULL) {
        return;
    }

    Node *p = NULL;
    Node *temp = NULL;
    while (aux != NULL && aux->next != NULL) {
        p = aux;
        while (p != NULL && p->next != NULL) {
            if (p->next->value == aux->value) {
                temp = p->next;
                p->next = temp->next;
                free(temp);
            }

            p = p->next;
        }

        aux = aux->next;
    }
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

    printLinkedList(l);
    removeDuplicates(l);
    printLinkedList(l);
    destroyLinkedList(l);
    return 0;
}