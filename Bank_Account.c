#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Account
{
    int accountNumber;
    char name[50];
    float balance;
};


int accountExists(int accNo)
{
    FILE *fp;
    struct Account acc;

    fp = fopen("accounts.dat", "rb");

    if (fp == NULL)
        return 0;

    while (fread(&acc, sizeof(acc), 1, fp))
    {
        if (acc.accountNumber == accNo)
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}


void createAccount()
{
    FILE *fp;
    struct Account acc;

    printf("\nEnter Account Number: ");
    scanf("%d", &acc.accountNumber);

    if (accountExists(acc.accountNumber))
    {
        printf("Account already exists!\n");
        return;
    }

    printf("Enter Account Holder Name: ");
    scanf(" %49[^\n]", acc.name);

    acc.balance = 0;

    fp = fopen("accounts.dat", "ab");

    if (fp == NULL)
    {
        printf("File Error!\n");
        return;
    }

    fwrite(&acc, sizeof(acc), 1, fp);
    fclose(fp);

    printf("\nAccount Created Successfully!\n");
}


void saveTransaction(int accNo, char type[], float amount,
                     float balance)
{
    FILE *fp;

    fp = fopen("transactions.txt", "a");

    if (fp == NULL)
        return;

    fprintf(fp, "Account: %d | Type: %s | Amount: %.2f | Balance: %.2f\n",
            accNo, type, amount, balance);

    fclose(fp);
}


void deposit()
{
    FILE *fp;
    struct Account acc;
    int accNo, found = 0;
    float amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    fp = fopen("accounts.dat", "rb+");

    if (fp == NULL)
    {
        printf("No accounts found!\n");
        return;
    }

    while (fread(&acc, sizeof(acc), 1, fp))
    {
        if (acc.accountNumber == accNo)
        {
            found = 1;

            printf("Enter Deposit Amount: ");
            scanf("%f", &amount);

            if (amount <= 0)
            {
                printf("Invalid Amount!\n");
                break;
            }

            acc.balance += amount;

            fseek(fp, -(long)sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);

            saveTransaction(accNo, "Deposit", amount,
                            acc.balance);

            printf("Money Deposited Successfully!\n");
            printf("Current Balance: %.2f\n", acc.balance);

            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("Account Not Found!\n");
}


void withdraw()
{
    FILE *fp;
    struct Account acc;
    int accNo, found = 0;
    float amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    fp = fopen("accounts.dat", "rb+");

    if (fp == NULL)
    {
        printf("No accounts found!\n");
        return;
    }

    while (fread(&acc, sizeof(acc), 1, fp))
    {
        if (acc.accountNumber == accNo)
        {
            found = 1;

            printf("Enter Withdrawal Amount: ");
            scanf("%f", &amount);

            if (amount <= 0)
            {
                printf("Invalid Amount!\n");
            }
            else if (amount > acc.balance)
            {
                printf("Insufficient Balance!\n");
            }
            else
            {
                acc.balance -= amount;

                fseek(fp, -(long)sizeof(acc), SEEK_CUR);
                fwrite(&acc, sizeof(acc), 1, fp);

                saveTransaction(accNo, "Withdrawal",
                                amount, acc.balance);

                printf("Withdrawal Successful!\n");
                printf("Remaining Balance: %.2f\n",
                       acc.balance);
            }

            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("Account Not Found!\n");
}


void displayAccount()
{
    FILE *fp;
    struct Account acc;
    int accNo, found = 0;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    fp = fopen("accounts.dat", "rb");

    if (fp == NULL)
    {
        printf("No accounts found!\n");
        return;
    }

    while (fread(&acc, sizeof(acc), 1, fp))
    {
        if (acc.accountNumber == accNo)
        {
            found = 1;

            printf("\n----- ACCOUNT DETAILS -----\n");
            printf("Account Number: %d\n", acc.accountNumber);
            printf("Account Holder: %s\n", acc.name);
            printf("Account Balance: %.2f\n", acc.balance);

            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("Account Not Found!\n");
}


void transactionHistory()
{
    FILE *fp;
    char ch;

    fp = fopen("transactions.txt", "r");

    if (fp == NULL)
    {
        printf("\nNo Transaction Records Found!\n");
        return;
    }

    printf("\n----- TRANSACTION HISTORY -----\n");

    while ((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
    }

    fclose(fp);
}


int main()
{
    int choice;

    do
    {
        printf("\n\n================================");
        printf("\n     BANKING MANAGEMENT SYSTEM");
        printf("\n================================");
        printf("\n1. Create Account");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Display Account Details");
        printf("\n5. Transaction History");
        printf("\n6. Exit");

        printf("\n\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createAccount();
                break;

            case 2:
                deposit();
                break;

            case 3:
                withdraw();
                break;

            case 4:
                displayAccount();
                break;

            case 5:
                transactionHistory();
                break;

            case 6:
                printf("\nThank You for Using Our Banking System!\n");
                break;

            default:
                printf("\nInvalid Choice! Try Again.\n");
        }

    } while (choice != 6);

    return 0;
}