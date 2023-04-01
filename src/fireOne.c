#include "../include/headerA3.h"
void fireOne (a3Emp ** headLL, int whichOne){
    struct employee * ptr;
    struct employee * tmp;
    ptr = *headLL;
    int i;
    for(i=1;i<whichOne;i++){
        if(ptr != NULL){
            ptr = ptr->nextEmployee;
        }
    }
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
        ptr = tmp;
    }        
}