// By Nehan mohammad
// 08-October-26, Thursday, question no: gate_linked_list_optimized

#include <stdio.h>
#include <stdlib.h>
#include "libs/listgen.h"

int find(int query, sadish *list) {
    sadish *curr = list;
    while (curr != NULL) {
        if ((int)curr->data == query) return 1;
        curr = curr->next;
    }
    return 0;
}

int main() {
    FILE *fp1 = fopen("a.dat", "r");
    FILE *fp2 = fopen("b.dat", "r");

    // Load data directly into vectors v1 and v2
    sadish *v1 = loadVec(fp1, 9);
    sadish *v2 = loadVec(fp2, 7);
    fclose(fp1);
    fclose(fp2);

    // Perform operations directly on v1 (L1)
    sadish *ptr1 = v1;
    int query;
    while (ptr1->next != NULL) {
        query = (int)ptr1->next->data;
        if (find(query, v2))
            ptr1->next = ptr1->next->next;
        else
            ptr1 = ptr1->next;
    }

    // Count remaining nodes
    int count = 0;
    sadish *curr = v1;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }

    // Allocate vectors into avyuh at the end for matrix representation
    avyuh *mat = (avyuh *)malloc(sizeof(avyuh));
    mat->vector = v1;
    mat->next = (avyuh *)malloc(sizeof(avyuh));
    mat->next->vector = v2;
    mat->next->next = NULL;

    printf("Number of nodes in L1 after execution: %d\n", count);
    printList(mat);

    return 0;
}

