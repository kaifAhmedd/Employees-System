#include "../include/headerA3.h"
// we first go over each employees id and store each id in an array
// we use the bubble sort logic and method to sort the array of ids in order
// we then use a forloop to print each employee and their data sorted using the lookonempID functon and the print one function
// we get the postion of the employees ids from least to greated and we use printall at the postion of eac id to print the sorted employees
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