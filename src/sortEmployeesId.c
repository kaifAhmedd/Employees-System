#include "../include/headerA3.h"
void sortEmployeesId (struct employee * headLL){
    struct employee * ptr;
    int tmp;
    int i = 0;
    int j = 0;
    int position = 0;
    int employeeCount = 0;
    int * empArray;
    ptr = headLL;
    employeeCount = countEmployees (headLL);
    empArray = malloc(sizeof(int)*employeeCount);
    ptr = headLL;
    while(ptr!=NULL){
        empArray[i] = ptr->empId;
        ptr = ptr->nextEmployee;
        i++;
    }
    for(i=0;i<employeeCount-1;i++){
        for(j=0;j<employeeCount-i-1;j++){
            if(empArray[j] > empArray[j+1]){
                tmp = empArray[j];
                empArray[j] = empArray[j+1];
                empArray[j+1] = tmp;
            }
        }
    }

    ptr = headLL;
    for(i=0;i<employeeCount;i++){
        position = lookOnId (headLL, empArray[i]);
        printOne (headLL, position);
    }
}