// By Nehan mohammad
// 08-October-26, Thursday, question no: load_lists_avyuh

#include <stdio.h>
#include <stdlib.h>
#include "libs/listgen.h"

int main() {
    // Open data files for list 1 and list 2
    FILE *fp1 = fopen("a.dat", "r");
    FILE *fp2 = fopen("b.dat", "r");

    // Load each file into respective sadish vectors
    sadish *v1 = loadVec(fp1, 9);
    sadish *v2 = loadVec(fp2, 7);
    fclose(fp1);
    fclose(fp2);

    // Construct the avyuh matrix structure to hold both vectors
    avyuh *mat = (avyuh *)malloc(sizeof(avyuh));
    mat->vector = v1;
    mat->next = (avyuh *)malloc(sizeof(avyuh));
    mat->next->vector = v2;
    mat->next->next = NULL;

    // Print the combined matrix containing both lists
    printList(mat);

    return 0;
}

