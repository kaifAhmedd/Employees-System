#include "../include/headerA3.h"
// we get our first name using strtok on the string passed into the function
// we copy the first name to the variable firstName
// we get our lastname using strtok
// we then see that if first name matched the employees first name as well as the lst then we return the positon otherwise we 
// go to the next employee and increment the postion count
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