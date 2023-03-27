#include "../include/headerA3.h"
int main (int argc, char * argv[]) {
    // we define variables here
    char fileName[MAX_LENGTH] = "proFile.txt";

    struct employee *head = NULL;
    // we call our helper function
    loadEmpData (&head, fileName);
    printf("\n");

    printf("Function 2 execution");
    printf("\n");
    printf("\n");
    printAll (head);
    printf("\n");
    return 0;
}