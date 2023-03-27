#include "../include/headerA3.h"
int main (int argc, char * argv[]) {
    // we define variables here
    char fileName[MAX_LENGTH] = "proFile.txt";

    struct employee *head = NULL;
    // we call our helper function
    loadEmpData (&head, fileName);
    printf("\n");

    // main for function 1
    printf("Function 1 execution");
    printf("\n");
    printf("\n");
    recruitEmployee (&head);
    printf("\n");

    // main for function 2
    printf("Function 2 execution");
    printf("\n");
    printf("\n");
    printAll (head);
    printf("\n");
    return 0;
}