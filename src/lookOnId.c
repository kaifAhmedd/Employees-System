#include "../include/headerA3.h"
int lookOnId (struct employee * headLL, int whichEmpId){
    struct employee * ptr;
    ptr = headLL;
    int employeePosition = 1;
    while(ptr!=NULL){
        if(whichEmpId == ptr->empId){
            return employeePosition;
        }
        else{
            ptr = ptr->nextEmployee;
            employeePosition++;
        }
    }
    return -1;
}