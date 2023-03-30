#include "../include/headerA3.h"
int main (int argc, char * argv[]) {
    // we define variables here
    char fileName[MAX_LENGTH] = "proFile.txt";
    struct employee *head = NULL;
    int whichOne = 0;
    int empId = 0;
    int position = 0;
    int employeeCount = 0;
    char fullName[100];
    int size = 0;
    int choice = 0;
    char cont = 'y';
    // we call our helper function
    loadEmpData (&head, fileName);
    printf("\n");

    while(cont == 'y'){
        printf("Choose a menu option: ");
        scanf("%d", &choice);
        printf("\n");

        if(choice == 1){
            // main for function 1
            printf("Function 1 execution");
            printf("\n");
            printf("\n");
            recruitEmployee (&head);
            printf("\n");
        }
        else if(choice == 2){
            // main for function 2
            printf("Function 2 execution");
            printf("\n");
            printf("\n");
            printAll (head);
            printf("\n");
        }
        else if(choice == 3){
            //main for function 3
            printf("Function 3 execution");
            printf("\n");
            printf("Enter a position: ");
            scanf("%d", &whichOne);
            printf("\n");
            printOne (head, whichOne);
        }
        else if(choice == 4){
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
        }
        else if(choice == 5){
            //Main for function 5
            printf("Function 5 execution");
            printf("\n");
            printf("Enter employees first and last name: ");
            getchar();
            fgets(fullName, 100 , stdin);
            size = strlen(fullName);
            fullName[size-1] = '\0';
            
            position = lookOnFullName (head, fullName);
            if(position != -1){
                printf("This employee is on position %d", position);
                printf("\n");
            }
            else{
                printf("Sorry we can't find the employee. Please enter another name! ");
                printf("\n");
            }
            printf("\n");
        }
        else if(choice == 6){
            //main for function 6
            printf("Function 6 execution");
            printf("\n");
            employeeCount = countEmployees(head);
            printf("Total number of employees = %d", employeeCount);
            printf("\n");
        }
        else if(choice == 7){

        }
        else if(choice == 8){

        }
        else if(choice == 9){

        }

        printf("\n");
        printf("Would you like to continue and go back to menu? Enter 'y' for yes and 'n' for no: ");
        scanf(" %c", &cont);
    }
    return 0;
}