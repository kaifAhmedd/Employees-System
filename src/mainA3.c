#include "../include/headerA3.h"
int main (int argc, char * argv[]) {
    // we define variables here
    char fileName[MAX_LENGTH] = "proFile.txt";

    struct employee *head = NULL;
    int whichOne = 0;
    int empId = 0;
    int position = 0;
    int employeeCount = 0;
    // we call our helper function
    loadEmpData (&head, fileName);
    printf("\n");

    // main for function 1
    printf("Function 1 execution");
    printf("\n");
    printf("\n");
    recruitEmployee (&head);
    printf("\n");

    // main for function 2
    printf("Function 2 execution");
    printf("\n");
    printf("\n");
    printAll (head);
    printf("\n");

    //main for function 3
    printf("Function 3 execution");
    printf("\n");
    printf("Enter a position: ");
    scanf("%d", &whichOne);
    printf("\n");
    printOne (head, whichOne);

    //main for function 4
    printf("Function 4 execution");
    printf("\n");
    printf("Enter an employee ID: ");
    scanf("%d", &empId);
    printf("\n");
    position = lookOnId(head, empId);
    if(position != -1){
        printf("This employee is on position %d", position);
        printf("\n");
    }
    else{
        printf("Sorry we can't find the employee. Please enter another ID! ");
        printf("\n");
    }
    printf("\n");

    //main for function 6
    printf("Function 6 execution");
    printf("\n");
    employeeCount = countEmployees(head);
    printf("Total number of employees = %d", employeeCount);
    printf("\n");
    return 0;
}