#include "../include/headerA3.h"
// this function fires every employee in the linked list
// while ptr isnt null we free each dependent of the employee 
// we free the dependents
//we store the next employee access in tmp
//we free ptr and we move onto the next employee
void fireAll (a3Emp ** headLL){
    struct employee * ptr;
    struct employee * tmp;
    ptr = *headLL;
    int i = 0;
    while(ptr!=NULL){
        for(i=0;i<ptr->numDependents;i++){
            free(ptr->dependents[i]);
        }
        free(ptr->dependents);
        tmp = ptr->nextEmployee;
        free(ptr);
        ptr = tmp;
    }
    *headLL = NULL;
}