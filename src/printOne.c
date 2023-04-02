#include "../include/headerA3.h"
// we use a forloop to go move through employees by the number provided to us by the user
// this allows us to get tothe desired employees position
// we then see that if ptr is null then it means that the employee does not exist at the position
// if they do we rint all their info such as id,first and last name, and depdendents
void printOne (struct employee * headLL, int whichOne){
    struct employee * ptr;
    ptr = headLL;
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
    printf("Employee id: %d", ptr->empId);
    printf("\n");
    printf("First name: %s", ptr->fname);
    printf("\n");
    printf("Last name: %s", ptr->lname);
    printf("\n");
    printf("Dependents[%d]: ", ptr->numDependents);
    for(i=0;i< ptr->numDependents;i++){
        printf("%s ", ptr->dependents[i]);
    }
    printf("\n");
    printf("\n");
    }        
}