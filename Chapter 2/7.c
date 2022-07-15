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

Node *getListTail(LinkedList *l, int *length) {
    *length = 0;
    if (l == NULL) {
        return NULL;
    }

    Node *p = l->header;
    *length = 1;

    while (p != NULL && p->next != NULL) {
        *length = *length + 1;
        p = p->next;
    }

    if (p != NULL) {
        *length = *length + 1;
    }

    return p;
}

Node *intersection(LinkedList *l1, LinkedList *l2) {
    if (l1 == NULL || l2 == NULL) {
        return NULL;
    }

    int len1 = 0;
    Node *tail1 = getListTail(l1, &len1);

    int len2 = 0;
    Node *tail2 = getListTail(l2, &len2);

    if (tail1 != tail2 || tail1 == NULL ||tail2 == NULL) {
        return NULL;
    }

    int diff = 0;
    Node *p1 = l1->header;
    Node *p2 = l2->header;
    if (len1 > len2) {
        diff = len1 - len2;
        for (int i = 0; i < diff; i++) {
            p1 = p1->next;
        }
    }
    else if (len1 < len2) {
        diff = len2 - len1;
        for (int i = 0; i < diff; i++) {
            p2 = p2->next;
        }        
    }

    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1;
}

int main() {
    Node *n1_1 = (Node *)malloc(sizeof(Node));
    n1_1->value = 3;
    Node *n1_2 = (Node *)malloc(sizeof(Node));
    n1_2->value = 1;
    Node *n1_3 = (Node *)malloc(sizeof(Node));
    n1_3->value = 5;
    Node *n1_4 = (Node *)malloc(sizeof(Node));
    n1_4->value = 9;
    Node *n1_5 = (Node *)malloc(sizeof(Node));
    n1_5->value = 7;
    Node *n1_6 = (Node *)malloc(sizeof(Node));
    n1_6->value = 2;
    Node *n1_7 = (Node *)malloc(sizeof(Node));
    n1_7->value = 1;

    Node *n2_1 = (Node *)malloc(sizeof(Node));
    n2_1->value = 4;
    Node *n2_2 = (Node *)malloc(sizeof(Node));
    n2_2->value = 6;

    n1_1->next = n1_2;
    n1_2->next = n1_3;
    n1_3->next = n1_4;
    n1_4->next = n1_5;
    n1_5->next = n1_6;
    n1_6->next = n1_7;
    n1_7->next = NULL;

    n2_1->next = n2_2;
    n2_2->next = n1_5;

    LinkedList *l1 = createLinkedList();
    l1->header = n1_1;
    LinkedList *l2 = createLinkedList();
    l2->header = n2_1;

    Node *common = intersection(l1, l2);
    if (common == NULL) {
        printf("There is no intersection");
    }
    else {
        printf("The two lists provided intersect at node %d\n", common->value);
    }
    
    free(n1_1);
    free(n1_2);
    free(n1_3);
    free(n1_4);
    free(n1_5);
    free(n1_6);
    free(n1_7);
    free(n2_1);
    free(n2_2);
    return 0;
}