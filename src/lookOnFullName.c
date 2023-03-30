#include "../include/headerA3.h"
int lookOnFullName (struct employee * headLL, char whichName [100]){
    char firstName[100];
    char lastName[100];
    char * token;
    struct employee * ptr;
    ptr = headLL;
    int employeePosition = 1;

    token = strtok(whichName, " ");
    strcpy(firstName, token);
    token = strtok(NULL, " ");
    strcpy(lastName, token);
    while(ptr!=NULL){
        if(strcmp(firstName, ptr->fname) == 0 && strcmp(lastName, ptr->lname) == 0){
            return employeePosition;
        }
        else{
            ptr = ptr->nextEmployee;
            employeePosition++;
        }
    }
    return -1;

}