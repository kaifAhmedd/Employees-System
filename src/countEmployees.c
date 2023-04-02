#include "../include/headerA3.h"
// this function goes untill ptr is null and it adds 1 to employee count each time there is an employee
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