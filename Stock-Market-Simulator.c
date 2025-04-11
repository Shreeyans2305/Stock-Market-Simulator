//Stock Market Simulator (PRC-Microproject) Sem 2 --> A060-Shreeyans Vichare
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User
{
    char name[50];
    float balance;
    char password[5];
};
struct Stock
{
    const char *name;
    const char *symbol;
    float current_price;
    float past_price;
    float deviation;
    int user_holding;
};
void Initilize_Stocks(struct Stock stocks[20]);
void Initilize_User(struct User *User_ptr);
void main()
{
    //User initialization 
    struct User *User_ptr, user1;
    User_ptr = &user1;
    Initilize_User(User_ptr);

    //Initializing Stocks
    
    struct Stock stocks[20];
    Initilize_Stocks(stocks);


    //Displaying Stocks
    /*
    printf("\n Name \t Symbol \t Stock Price \t Deviation");
    printf("\n %s \t %s \t\t %.2f \t (+2.39)",stocks[0].name,stocks[0].symbol,stocks[0].current_price);*/
}
void Initilize_User(struct User *User_ptr)
{
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


void Initilize_Stocks(struct Stock stocks[20])
{
    stocks[0].name = "APPLE";
    stocks[0].symbol = "AAPL";
    stocks[0].current_price = 1707.20;
    stocks[0].user_holding = 0;

    stocks[1].name = "MICROSOFT";
    stocks[1].symbol = "MSFT";
    stocks[1].current_price = 3300.00;
    stocks[1].user_holding = 0;

    stocks[2].name = "NVIDIA";
    stocks[2].symbol = "NVDA";
    stocks[2].current_price = 949.40;
    stocks[2].user_holding = 0;

    stocks[3].name = "AMAZON";
    stocks[3].symbol = "AMZN";
    stocks[3].current_price = 1576.30;
    stocks[3].user_holding = 0;

    stocks[4].name = "BERKSHIRE HATHWAY";
    stocks[4].symbol = "BRK-B";
    stocks[4].current_price = 4496.50;
    stocks[4].user_holding = 0;

    stocks[5].name = "ALPHABET (GOOGLE)";
    stocks[5].symbol = "GOOG";
    stocks[5].current_price = 1369.50;
    stocks[5].user_holding = 0;

    stocks[6].name = "META";
    stocks[6].symbol = "META";
    stocks[6].current_price = 4643.60;
    stocks[6].user_holding = 0;

    stocks[7].name = "TESLA";
    stocks[7].symbol = "TSLA";
    stocks[7].current_price = 2139.80;
    stocks[7].user_holding = 0;

    stocks[8].name = "TOYOTA";
    stocks[8].symbol = "TM";
    stocks[8].current_price = 1452.70;
    stocks[8].user_holding = 0;

    stocks[9].name = "VISA";
    stocks[9].symbol = "V";
    stocks[9].current_price = 2881.90;
    stocks[9].user_holding = 0;

    stocks[10].name = "TATA STEEL";
    stocks[10].symbol = "TTSL";
    stocks[10].current_price = 133.42;
    stocks[10].user_holding = 0;

    stocks[11].name = "CANARA BANK";
    stocks[11].symbol = "CANBK";
    stocks[11].current_price = 90.53;
    stocks[11].user_holding = 0;

    stocks[12].name = "INFOSYS";
    stocks[12].symbol = "INFY";
    stocks[12].current_price = 1416.80;
    stocks[12].user_holding = 0;

    stocks[13].name = "RELIANCE INDUSTRIES";
    stocks[13].symbol = "REL";
    stocks[13].current_price = 1220.00;
    stocks[13].user_holding = 0;

    stocks[14].name = "TATA MOTORS";
    stocks[14].symbol = "TTMR";
    stocks[14].current_price = 596.00;
    stocks[14].user_holding = 0;

    stocks[15].name = "HDFC BANK";
    stocks[15].symbol = "HDFC";
    stocks[15].current_price = 1805.20;
    stocks[15].user_holding = 0;

    stocks[16].name = "BHARAT ELECTRONICS";
    stocks[16].symbol = "BEL";
    stocks[16].current_price = 285.30;
    stocks[16].user_holding = 0;

    stocks[17].name = "STATE BANK OF INDIA";
    stocks[17].symbol = "SBI";
    stocks[17].current_price = 753.85;
    stocks[17].user_holding = 0;

    stocks[18].name = "PUNJAB NATIONAL BANK";
    stocks[18].symbol = "PNB";
    stocks[18].current_price = 96.08;
    stocks[18].user_holding = 0;

    stocks[19].name = "ICICI BANK";
    stocks[19].symbol = "ICICI";
    stocks[19].current_price = 1312.05;
    stocks[19].user_holding = 0;

    printf("\nStocks Initialized Sucessfully");
}
