#include "../include/headerA3.h"
// we use a while loop to go to the end of the linked list which is where we will put the new employee(s)
// once we are at the end we malloc a spot for the employee
// we then set our temporary pointer to ptr so our head is at the new created node
// we ask the user for the employees first and last name.
// we malloc spot for dependent and we malloc it by the max amount of letter it can have
// we then ask for the name of the dependent
// we ask if there are any more and if so we realloc to create a box for that dependent and we increment the depednet count
// if they say no then we set numdepdetns to our number of dependents and we set out nextemployee to null
// we then print the number of dependents
// we then calculate the id using the sun of the ascii values in the name
// if the id is the same as any other then we use rand to generate a randon id between 1 and 1000 for the employee
// we then store that id into the node
// we print the employee id that has been generated
void recruitEmployee (struct employee ** headLL){   
    struct employee * ptr;
    struct employee * tmp;
    tmp = *headLL;
    char choice;
    int i = 0;
    int dependentCount = 1;
    int ascii = 0;
    int empid = 0;
    int randomizer = rand() % 1000;

    if(*headLL == NULL){
        ptr = malloc(sizeof(struct employee));
        *headLL = ptr;
    }
    else{
        while(tmp->nextEmployee != NULL){
            tmp = tmp->nextEmployee;
        }
        ptr = malloc(sizeof(struct employee));
        tmp->nextEmployee = ptr;
    }
        
    printf("Enter the first name of the employee: ");
    scanf("%s", ptr->fname);
    printf("\n");
    printf("Enter the last name of the employee: ");
    scanf("%s", ptr->lname);
    printf("\n");
    ptr->dependents = malloc(sizeof(char*)*1);
    ptr->dependents[0] = malloc(sizeof(char)*MAX_LENGTH);
    while(choice != 'n' && choice != 'N'){
        printf("Enter the name of dependent #%d: ", dependentCount);
        scanf("%s", ptr->dependents[i]);
        i++;
        printf("Do you have anymore dependents. Enter 'y' for yes and 'n' for no? ");
        scanf(" %c", &choice);
        if(choice != 'n' && choice != 'N'){
            ptr->dependents = realloc(ptr->dependents, sizeof(char*)* (i+1));
            ptr->dependents[i] = malloc(sizeof(char)*MAX_LENGTH);
            dependentCount++;
        }
        printf("\n");
    }
    ptr->numDependents = dependentCount;
    ptr->nextEmployee = NULL;
    printf("\n");
    printf("You have %d dependent(s).", dependentCount);
    printf("\n");

    for(i=0;i<strlen(ptr->fname);i++){
        ascii+=(int)ptr->fname[i];
    }
    empid = ascii + strlen(ptr->lname);

    tmp = *headLL;
    while(tmp->nextEmployee != NULL){
        if(empid == tmp->empId){
            empid = empid + randomizer;
        }
        tmp = tmp->nextEmployee;
    }
    ptr->empId = empid;    
    printf("Your computer-generated empid is: %d", empid);
    printf("\n");
}