#include <stdio.h>


void openAccount(int accountNumbers[], float balances[], int *numAccounts);
void makeDeposit(int accountNumbers[], float balances[], int numAccounts);
void makeWithdrawal(int accountNumbers[], float balances[], int numAccounts);
void checkBalance(int accountNumbers[], float balances[], int numAccounts);

int main() {
    int accountNumbers[100];
    float balances[100];
    int numAccounts = 0;
    int choice;

    do {
        printf("\nWelcome to the Bank!\n");
        printf("1. Open an Account\n");
        printf("2. Make a Deposit\n");
        printf("3. Make a Withdrawal\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                openAccount(accountNumbers, balances, &numAccounts);
                break;
            case 2:
                makeDeposit(accountNumbers, balances, numAccounts);
                break;
            case 3:
                makeWithdrawal(accountNumbers, balances, numAccounts);
                break;
            case 4:
                checkBalance(accountNumbers, balances, numAccounts);
                break;
            case 5:
                printf("Exiting the bank. Have a great day!\n");
                break;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}

void openAccount(int accountNumbers[], float balances[], int *numAccounts) {
    printf("Enter your new account number: ");
    scanf("%d", &accountNumbers[*numAccounts]);
    printf("Enter your initial deposit: $");
    scanf("%f", &balances[*numAccounts]);
    (*numAccounts)++;
    printf("Account created successfully! Welcome to the bank!\n");
}

void makeDeposit(int accountNumbers[], float balances[], int numAccounts) {
    int accountNum;
    float amount;

    printf("Enter your account number: ");
    scanf("%d", &accountNum);

    int index = -1;
    for (int i = 0; i < numAccounts; i++) {
        if (accountNumbers[i] == accountNum) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Enter the amount you want to deposit: $");
        scanf("%f", &amount);
        balances[index] += amount;
        printf("Deposit successful. Your new balance: $%.2f\n", balances[index]);
    } else {
        printf("Account not found. Please check your account number.\n");
    }
}

void makeWithdrawal(int accountNumbers[], float balances[], int numAccounts) {
    int accountNum;
    float amount;

    printf("Enter your account number: ");
    scanf("%d", &accountNum);

    int index = -1;
    for (int i = 0; i < numAccounts; i++) {
        if (accountNumbers[i] == accountNum) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Enter the amount you want to withdraw: $");
        scanf("%f", &amount);
        if (amount <= balances[index]) {
            balances[index] -= amount;
            printf("Withdrawal successful. Your new balance: $%.2f\n", balances[index]);
        } else {
            printf("Insufficient funds. Try a smaller amount.\n");
        }
    } else {
        printf("Account not found. Please check your account number.\n");
    }
}

void checkBalance(int accountNumbers[], float balances[], int numAccounts) {
    int accountNum;

    printf("Enter your account number: ");
    scanf("%d", &accountNum);

    int index = -1;
    for (int i = 0; i < numAccounts; i++) {
        if (accountNumbers[i] == accountNum) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Your current balance: $%.2f\n", balances[index]);
    } else {
        printf("Account not found. Please check your account number.\n");
    }
}
