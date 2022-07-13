#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letter;
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

int insertElement(LinkedList *l, char elem) {
    if (l == NULL) {
        return 1;
    }

    Node *n = (Node *) malloc(sizeof(Node));
    if (n == NULL) {
        return 1;
    }

    n->next = NULL;
    n->letter = elem;

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
        printf("%c", aux->letter);
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

int isPalindrome(LinkedList *l) {
    if (l == NULL) {
        return -1;
    }

    LinkedList *reverse = createLinkedList();
    if (reverse == NULL) {
        return -1;
    }

    Node *p = l->header;
    Node *tmp = NULL;
    while (p != NULL) {
        Node *newBlock = (Node *) malloc(sizeof(Node));
        if (newBlock == NULL) {
            return -1;
        }

        newBlock->letter = p->letter;
        tmp = reverse->header;
        reverse->header = newBlock;
        reverse->header->next = tmp;
        p = p->next;
    }

    printLinkedList(reverse);

    Node *q = reverse->header;
    p = l->header;
    while (p != NULL && p->letter == q->letter) {
        p = p->next;
        q = q->next;
    }

    if (p == NULL) {
        return 1;
    }

    return 0;
}

int main() {
    printf("Insert the number of characters to be stored in your linked list : \n");
    int n;
    scanf(" %d", &n);

    LinkedList *l = createLinkedList();
    printf("Now insert each element in a unique line: \n");
    char letter;
    for(int i=0; i<n; i++) {
        scanf(" %c", &letter);
        insertElement(l, letter);
    }

    printLinkedList(l);
    printf("isPalindrome: %d\n", isPalindrome(l));
    destroyLinkedList(l);
    return 0;
}