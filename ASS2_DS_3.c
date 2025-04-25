/*Create a Structure called BankMgmt with AccNumber, CustName, AvlBalance,
AccType as members. Implement a Bank management Application as menu driven
program for the above said Structure scenario.
Menu Option:
1. Withdrawal 2. Deposit 3. Display Balance 4. Exit
If option
1 is chosen- Amount can be withdrawn from the account (Withdrawn amount
should be given as input). For withdrawal the condition is- the AvlBalance must be
greater than withdrawn amount).
2 is chosen- Amount can be deposited to the account (the deposited amount
should be given as input). The deposited amount should be reflected in AvlBalance of
the account.
3 is chosen- Current available balance (AvlBalance) of the AccNumber should
be Displayed with other details
4 is chosen- Exit from the application
Sample Input:
SB 100155 VenkatKrishna 4500.00 Saving*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure
typedef struct {
    int AccNumber;
    char CustName[100];
    double AvlBalance;
    char AccType[20];
} BankMgmt;

// Function prototypes
void withdraw(BankMgmt *account);
void deposit(BankMgmt *account);
void displayBalance(const BankMgmt *account);

int main() {
    BankMgmt account;
    int choice;
    double amount;

    // Sample Input
    account.AccNumber = 100155;
    strcpy(account.CustName, "VenkatKrishna");
    account.AvlBalance = 4500.00;
    strcpy(account.AccType, "Saving");

    while (1) {
        printf("\n--- Bank Management System ---\n");
        printf("1. Withdrawal\n");
        printf("2. Deposit\n");
        printf("3. Display Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                withdraw(&account);
                break;
            case 2:
                deposit(&account);
                break;
            case 3:
                displayBalance(&account);
                break;
            case 4:
                printf("Exiting the application.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void withdraw(BankMgmt *account) {
    double amount;
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);

    if (amount > account->AvlBalance) {
        printf("Insufficient balance. Transaction failed.\n");
    } else {
        account->AvlBalance -= amount;
        printf("Withdrawal successful. New balance: %.2lf\n", account->AvlBalance);
    }
}

void deposit(BankMgmt *account) {
    double amount;
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);

    account->AvlBalance += amount;
    printf("Deposit successful. New balance: %.2lf\n", account->AvlBalance);
}

void displayBalance(const BankMgmt *account) {
    printf("\n--- Account Details ---\n");
    printf("Account Number: %d\n", account->AccNumber);
    printf("Customer Name: %s\n", account->CustName);
    printf("Account Type: %s\n", account->AccType);
    printf("Available Balance: %.2lf\n", account->AvlBalance);
}