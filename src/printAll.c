#include "../include/headerA3.h"
// while ptr is not null we print all the info of the employees including id,firs tnad last name, and their dependents
// we also increment the employee count by 1 eah time so that we can provide the total number of employees
void printAll (struct employee * headLL){
    struct employee * ptr;
    ptr = headLL;
    int employeeCount  = 1;
    int i = 0;
    if(headLL == NULL){
        printf("This linked list is empty! ");
    }
    else{
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
}