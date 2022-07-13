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

LinkedList *sumLists(LinkedList *number1, LinkedList *number2) {
    if (number1 == NULL || number2 == NULL) {
        return NULL;
    }

    LinkedList *result = createLinkedList();
    Node *result_last = result->header;
    Node *p1 = number1->header;
    Node *p2 = number2->header;
    int val = 0;
    int carry = 0;
    while (p1 != NULL || p2 != NULL) {
        Node *newBlock = (Node *)malloc(sizeof(Node));
        newBlock->next = NULL;
        if (p1 != NULL) {
            val += p1->value;
            p1 = p1->next;
        }
        if (p2 != NULL) {
            val += p2->value;
            p2 = p2->next;
        }

        val += carry;
        if (val >= 10) {
            carry = 1;
            val = val%10;
        }
        else {
            carry = 0;
        }

        newBlock->value = val;
        val = 0;
        if (result_last == NULL) {
            result->header = newBlock;
            result_last = result->header;
        }
        else {
            result_last->next = newBlock;
            result_last = result_last->next;
        }
    }

    return result;
}

int main() {
    printf("Insert the number of digits of the first number: \n");
    int n1;
    scanf(" %d", &n1);

    LinkedList *l1 = createLinkedList();
    printf("Now insert each digit in a unique line in reverse order: \n");
    int elem;
    for(int i=0; i<n1; i++) {
        scanf(" %d", &elem);
        insertElement(l1, elem);
    }

    printf("Insert the number of digits of the second number: \n");
    int n2;
    scanf(" %d", &n2);

    LinkedList *l2 = createLinkedList();
    printf("Now insert each digit in a unique line in reverse order: \n");
    for(int i=0; i<n2; i++) {
        scanf(" %d", &elem);
        insertElement(l2, elem);
    }

    printLinkedList(l1);
    printLinkedList(l2);
    LinkedList *sum = sumLists(l1, l2);
    printLinkedList(sum);
    destroyLinkedList(l1);
    destroyLinkedList(l2);
    return 0;
}