#include "../include/headerA3.h"
// this function fires the employee on the nth positon entered by the user
// if the postion is 1 then we delete the first node by freeing and we set the head to the next node after the one which got deleted
// if the position is not 1 then we set the previous variable to a node before the one we need to delete.
//once we delete the node we set previoud node next to the next node of the deleted node!
void fireOne (a3Emp ** headLL, int whichOne){
    struct employee * ptr;
    struct employee * tmp = NULL;
    struct employee * previousEmp = NULL;
    ptr = *headLL;
    int i;

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