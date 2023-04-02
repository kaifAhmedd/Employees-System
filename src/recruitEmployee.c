#include "../include/headerA3.h"
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
    while(tmp->nextEmployee != NULL){
        tmp = tmp->nextEmployee;
    }
    ptr = malloc(sizeof(struct employee));
    tmp->nextEmployee = ptr;
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
        printf("Do you have anymore dependents? ");
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