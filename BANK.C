#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure for one account
struct Account {
    int acc_no;
    char name[50];
    float balance;
};

// function declarations
void createAccount();
void depositMoney();
void withdrawMoney();
void checkBalance();
void listAccounts();

int main() {
    int choice;
    while (1) {
        printf("\n==== BANK ACCOUNT MANAGEMENT SYSTEM ====\n");
        printf("1. Create New Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. List All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                listAccounts();
                break;
            case 6:
                printf("Thank you for using the system!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to create new account
void createAccount() {
    FILE *fp;
    struct Account acc;
    fp = fopen("accounts.txt", "a"); // open file to append
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    printf("\nEnter Account Number: ");
    scanf("%d", &acc.acc_no);
    printf("Enter Name: ");
    scanf("%s", acc.name);
    printf("Enter Initial Deposit: ");
    scanf("%f", &acc.balance);

    fwrite(&acc, sizeof(struct Account), 1, fp);
    fclose(fp);
    printf("Account created successfully!\n");
}

// Function to deposit money
void depositMoney() {
    FILE *fp;
    struct Account acc;
    int acc_no, found = 0;
    float amount;

    fp = fopen("accounts.txt", "r+");
    if (fp == NULL) {
        printf("No accounts found!\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%d", &acc_no);
    while (fread(&acc, sizeof(struct Account), 1, fp)) {
        if (acc.acc_no == acc_no) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            acc.balance += amount;
            fseek(fp, -sizeof(struct Account), SEEK_CUR);
            fwrite(&acc, sizeof(struct Account), 1, fp);
            printf("Amount deposited successfully!\n");
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (!found)
        printf("Account not found!\n");
}

// Function to withdraw money
void withdrawMoney() {
    FILE *fp;
    struct Account acc;
    int acc_no, found = 0;
    float amount;

    fp = fopen("accounts.txt", "r+");
    if (fp == NULL) {
        printf("No accounts found!\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%d", &acc_no);
    while (fread(&acc, sizeof(struct Account), 1, fp)) {
        if (acc.acc_no == acc_no) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > acc.balance) {
                printf("Insufficient balance!\n");
            } else {
                acc.balance -= amount;
                fseek(fp, -sizeof(struct Account), SEEK_CUR);
                fwrite(&acc, sizeof(struct Account), 1, fp);
                printf("Amount withdrawn successfully!\n");
            }
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (!found)
        printf("Account not found!\n");
}

// Function to check balance
void checkBalance() {
    FILE *fp;
    struct Account acc;
    int acc_no, found = 0;

    fp = fopen("accounts.txt", "r");
    if (fp == NULL) {
        printf("No accounts found!\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%d", &acc_no);
    while (fread(&acc, sizeof(struct Account), 1, fp)) {
        if (acc.acc_no == acc_no) {
            printf("Account Holder: %s\n", acc.name);
            printf("Balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (!found)
        printf("Account not found!\n");
}

// Function to list all accounts
void listAccounts() {
    FILE *fp;
    struct Account acc;
    fp = fopen("accounts.txt", "r");
    if (fp == NULL) {
        printf("No accounts found!\n");
        return;
    }
    printf("\n---- All Accounts ----\n");
    printf("Acc_No\tName\tBalance\n");
    printf("--------------------------\n");
    while (fread(&acc, sizeof(struct Account), 1, fp)) {
        printf("%d\t%s\t%.2f\n", acc.acc_no, acc.name, acc.balance);
    }
    fclose(fp);
}
