#include "../include/headerA3.h"
void fireOne (a3Emp ** headLL, int whichOne){
    struct employee * ptr;
    struct employee * tmp = NULL;
    struct employee * previousEmp = NULL;
    ptr = *headLL;
    int i;

    // previousEmp = ptr;
    if(whichOne == 1){
        if(ptr == NULL){
            printf("The Linked list is empty!");
        }
        else{
        printf("\n");
        printf("Employee [Id: %d] fired.", ptr->empId);
        for(i=0;i<ptr->numDependents;i++){
            free(ptr->dependents[i]);
        }
        free(ptr->dependents);
        tmp = ptr->nextEmployee;
        free(ptr);
        *headLL = tmp;
        }
    }
    else{ 
        for(i=1;i<whichOne-1;i++){
            if(ptr != NULL){
                ptr = ptr->nextEmployee;
            }
        }
        previousEmp = ptr;
        ptr = ptr->nextEmployee;
        if(ptr == NULL){
            printf("Enter another postion, Employee does not exist!");
            printf("\n");
        }
        else{
            printf("\n");
            printf("Employee [Id: %d] fired.", ptr->empId);
            printf("\n");
            for(i=0;i<ptr->numDependents;i++){
                free(ptr->dependents[i]);
            }
            free(ptr->dependents);
            tmp = ptr->nextEmployee;
            free(ptr);
            previousEmp->nextEmployee = tmp;
        }        
    }
}