#include "../include/headerA3.h"
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