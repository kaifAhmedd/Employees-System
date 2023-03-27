#include "../include/headerA3.h"
void printOne (struct employee * headLL, int whichOne){
    struct employee * ptr;
    ptr = headLL;
    int i;
    for(i=1;i<whichOne;i++){
        ptr = ptr->nextEmployee;
    }
    printf("Employee id: %d", ptr->empId);
    printf("\n");
    printf("First name: %s", ptr->fname);
    printf("\n");
    printf("Last name: %s", ptr->lname);
    printf("\n");
    printf("Dependents[%d]: ", ptr->numDependents);
    for(i=0;i< ptr->numDependents;i++){
        printf("%s ", ptr->dependents[i]);
    }
    printf("\n");
    printf("\n");        
}