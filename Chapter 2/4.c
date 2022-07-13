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

LinkedList *partitionLinkedList(LinkedList *l, int partition) {
    if (l == NULL) {
        return NULL;
    }

    LinkedList *newList = createLinkedList();
    if (newList == NULL) {
        return NULL;
    }

    Node *p = l->header;
    Node *reference = newList->header;
    while (p != NULL) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->value = p->value;
        if (reference == NULL) {
            newNode->next = NULL;
            newList->header = newNode;
            reference = newNode;
        }
        else if (p->value < partition) {
                newNode->next = newList->header;
                newList->header = newNode;               
        }
        else {
            // Adjust reference
            while (reference->next != NULL && reference->value < partition) {
                reference = reference->next;
            }
            if (reference->value < partition) {
                newNode->next = NULL;
                reference->next = newNode;    
            }
            else {
                if (reference->next == NULL) {
                    reference->next = newNode;
                    newNode->next = NULL;
                }
                else {
                    newNode->next = reference->next;
                    reference->next = newNode;
                }
            }
        }

        p = p->next;
    }

    return newList;
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

    printf("Now insert the element which will be used as reference to partition the linked list: \n");
    int ref_val;
    scanf(" %d", &ref_val);

    printLinkedList(l);
    l = partitionLinkedList(l, ref_val);
    printLinkedList(l);
    destroyLinkedList(l);
    return 0;
}