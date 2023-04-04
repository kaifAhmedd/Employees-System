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

    // the user can continue as long as they enter y which indicates yes
    while(cont == 'y'){
        printf("Wecome to proFile!");
        printf("\n");
        for(i=0;i<50;i++){
            printf("-");
        }
        printf("\n");
        // menu options
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

        // option is 1 then we use the recruitEmployee function to add an employee
        if(choice == 1){
            // main for function 1
            printf("Function 1 execution");
            printf("\n");
            printf("\n");
            recruitEmployee (&head);
            printf("\n");
        }
        // if option is 2 then we use the printall function to print all the employees
        else if(choice == 2){
            // main for function 2
            printf("Function 2 execution");
            printf("\n");
            printf("\n");
            printAll (head);
            printf("\n");
        }
        // if option is 3 then we ask the enter the postion fo the employee that they want to print
        // we then call the function print one to print the employees data at the users position
        else if(choice == 3){
            //main for function 3
            printf("Function 3 execution");
            printf("\n");
            printf("Enter a position: ");
            scanf("%d", &whichOne);
            printf("\n");
            printOne (head, whichOne);
        }
        // we ask user to enter an id and we call the function lookOnId so that we can store the postion of the employee that it returns
        // we then see that f the postion is not -1 we print the postion fo theemployee otherwise we say that employe could not be found
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
        // we ask user to enter the first and last name of the employee using fgets
        // since fgets thats the whole line we need to set the letter of fullName to \0 at size-1
        // we then call the function and store the postion ofthe employee in the variable postion
        // we then see that if the postion isnt -1 we print the postion fo the employee other wise we say that the employee could not be found
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
                printf("Sorry we can't find the employee or the link list is empty. Please enter another name! ");
                printf("\n");
            }
            printf("\n");
        }
        //  if choice is 6 we call the function countEmployees and we store its returning value in the variable employeeCount
        // we then print the total number of employees in the LL
        else if(choice == 6){
            //main for function 6
            printf("Function 6 execution");
            printf("\n");
            employeeCount = countEmployees(head);
            printf("Total number of employees = %d", employeeCount);
            printf("\n");
        }
        // if choice is 7 then we promt the message of the sorted version of employees 
        // we then call the function sortEmployeesId and that prints the employeed data sorted accoring to ids
        else if(choice == 7){
            printf("Function 7 execution");
            printf("\n");
            printf("After sorting on empId, the employees are as follows: ");
            printf("\n");
            sortEmployeesId (head);
            printf("\n");
        }
        // if choice is 8 then we call the countemployees function to show how many employees their are boefre we fire someone
        // we then ask the user to enter a number depening on the user they want to fire
        // we pass the entered number into the function fireOne and we call it
        // we then call countemployees to show how amny employees their are after we fired employees
        else if(choice == 8){
            printf("Function 8 execution");
            printf("\n");
            employeeCount = countEmployees(head);
            if(employeeCount == 0){
                printf("The linked list is empty!");
            }
            else{
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
        }
        // if choice is 9 then we ask the user if they really want to fire everyone
        // if the user enter 'y' then we call the function firAll and we say that the linked list is empty
        else if(choice == 9){
            printf("Function 9 execution");
            printf("\n");
            employeeCount = countEmployees(head);
            if(employeeCount == 0){
                printf("The linked list is empty! ");
            }
            else{
                printf("Are you sure you want to fire everyone? Enter 'y' for yes and 'n' for no: ");
                scanf(" %c", &fire);
                printf("\n");
                if(fire == 'y'){
                    fireAll(&head);
                    printf("All fired. Linked list is now empty");
                }
            }
            printf("\n");
        }
        // if choice is 10 we free all employees and end the program
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