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
    char fire;
    int i = 0;
    // we call our helper function
    loadEmpData (&head, fileName);
    printf("\n");

    while(cont == 'y'){
        printf("Wecome to profle!");
        printf("\n");
        for(i=0;i<50;i++){
            printf("-");
        }
        printf("\n");
        printf("1. Add a new employee");
        printf("\n");
        printf("2. Print the data of all employees");
        printf("\n");
        printf("3. Print the data of the nth employee");
        printf("\n");
        printf("4. Search for employee based on their ID");
        printf("\n");
        printf("5. Search for employee based on their full name");
        printf("\n");
        printf("6. Count the total number of employees");
        printf("\n");
        printf("7. Sort the employees based on their ID's");
        printf("\n");
        printf("8. Remove the nth employee in the current LL");
        printf("\n");
        printf("9. Remove all employees in the current LL");
        printf("\n");
        printf("10 Exit");
        printf("\n");
        for(i=0;i<50;i++){
            printf("-");
        }
        printf("\n");
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
            printf("Function 7 execution");
            printf("\n");
            printf("After sorting on empId, the employees are as follows: ");
            printf("\n");
            sortEmployeesId (head);
            printf("\n");
        }
        else if(choice == 8){
            printf("Function 8 execution");
            printf("\n");
            employeeCount = countEmployees(head);
            printf("Currently there are %d employees.", employeeCount);
            printf("\n");
            printf("\n");
            printf("Which employee do you wish to fire - enter a value between 1 to %d: ", employeeCount);
            scanf("%d", &whichOne);
            printf("\n");
            fireOne (&head, whichOne);
            printf("\n");
            employeeCount = countEmployees(head);
            printf("There are now %d employees.", employeeCount);
            printf("\n");
        }
        else if(choice == 9){
            printf("Function 9 execution");
            printf("\n");
            printf("Are you sure you want to fire everyone? Enter 'y' for yes and 'n' for no: ");
            scanf(" %c", &fire);
            printf("\n");
            if(fire == 'y'){
                fireAll(&head);
                printf("All fired. Linked list is now empty");
            }
            printf("\n");
        }
        else if(choice == 10){
            fireAll(&head);
            return 0;
        }

        printf("\n");
        printf("Would you like to continue and go back to menu? Enter 'y' for yes and 'n' for no: ");
        scanf(" %c", &cont);
    }
    fireAll(&head);
    return 0;
}