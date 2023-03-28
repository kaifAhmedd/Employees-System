#include "../include/headerA3.h"
int countEmployees (a3Emp * headLL){
    struct employee * ptr;
    ptr = headLL;
    int employeeCount = 0;
    while(ptr!=NULL){
        ptr = ptr->nextEmployee;
        employeeCount++;
    }
    return employeeCount;
}