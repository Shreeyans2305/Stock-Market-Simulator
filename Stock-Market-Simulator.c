//Stock Market Simulator (PRC-Microproject) Sem 2 --> A060-Shreeyans Vichare
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User
{
    char name[50];
    float balance;
    char password[5];
    float arr[500];
};

void main()
{
    struct User *User_ptr, user1;
    //Add Intro Part
    User_ptr = &user1;
    printf("Enter your Username: ");
    fgets(User_ptr->name,sizeof(User_ptr->name),stdin);
    printf("Welcome to the Stock Market, ");
    puts(User_ptr->name);

    check:
    printf("Set a 4-digit pin: ");
    fgets(User_ptr->password,sizeof(User_ptr->password),stdin);
    if(strlen(User_ptr->password)!=4){
        printf("The pin must contain 4 digits!\n");
        goto check;
    }
    for(int i=0;i<4;i++){
        if(User_ptr->password[i]<'0' || User_ptr->password[i]>'9'){
            printf("The pin must only contain numerical values!\n");
            goto check;
        }
    }
    printf("Your PIN has been set!\n");

    printf("Enter the amount you wish to Deposit in your trading account: ");
    scanf("%f",&User_ptr->balance);
    printf("Your balance is %.2f",User_ptr->balance);
}