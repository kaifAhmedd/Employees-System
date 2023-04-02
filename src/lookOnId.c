#include "../include/headerA3.h"
// while ptr is not null we compare each empID with the id passed into the function and if they are the same then we return
// the positon otherwise we go to the next employee and increment the postion count
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