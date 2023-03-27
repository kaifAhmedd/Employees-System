#include "../include/headerA3.h"
void printAll (struct employee * headLL){
    struct employee * ptr;
    ptr = headLL;
    int employeeCount  = 1;
    int i = 0;
    while(ptr!=NULL){
        printf("Employee #%d",employeeCount);
        printf("\n");
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
        ptr = ptr->nextEmployee;
        employeeCount++;
    }
    employeeCount = employeeCount-1;
    printf("Currently, there are %d employees.", employeeCount);
}