// Stock Market Simulator (PRC-Microproject) Sem 2 --> A060-Shreeyans Vichare
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
struct User
{
    char name[50];
    float balance;
    char password[5];
    float current_holding;
    float previous_holding;
    int age;
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

int simulated = 0;

void Initilize_Stocks(struct Stock stocks[20]);
void Initilize_Stocks_2(struct Stock stocks[20]);
void Initilize_User(struct User *User_ptr);
void Display(struct Stock stocks[20]);
void Display_2(struct Stock stocks[20]);
void Portfolio(struct Stock stocks[20], struct User *User_ptr);
void Buy(struct Stock stocks[20], struct User *User_ptr);
void Sell(struct Stock stocks[20], struct User *User_ptr);
void Simulate(struct Stock stocks[20]);
void Withdraw(struct User *User_ptr);
void Deposit(struct User *User_ptr);
// Main Menu Function
void main()
{
    printf("\t\t\t\t\t\t\t\t\t STOCK MARKET SIMULATOR\n");
    // User initialization

    struct User *User_ptr, user1;
    User_ptr = &user1;
    Initilize_User(User_ptr);

    // Initializing Stocks

    struct Stock stocks[20];
    Initilize_Stocks(stocks);

    Display(stocks);

    int user_active = 1;
    while (user_active == 1)
    {
    simul_check:
        printf("\nMain Menu: \n");
        printf("Here is a list of commands: \n");
        printf("To view your Portfolio, type /p \n");
        printf("To Buy Stocks, type /b \n");
        printf("To Sell Stocks, type /s \n");
        printf("To Simulate the Stock Market, type /simulate \n");
        printf("To View Current Stock Prices, type /v \n");
        printf("To Deposit Funds, type /d \n");
        printf("To Withdraw Funds, type /w \n");
        printf("To End the Simulation, type /end \n");

        char command[5];
        printf("\n Enter your command: ");
        scanf("%s", &command);

        if (strcmp(command, "/p") == 0)
        {
            Portfolio(stocks, User_ptr);
        }
        else if (strcmp(command, "/b") == 0)
        {
            Buy(stocks, User_ptr);
        }
        else if (strcmp(command, "/s") == 0)
        {
            Sell(stocks, User_ptr);
        }
        else if (strcmp(command, "/simulate") == 0)
        {
            Simulate(stocks);
            goto simul_check;
        }
        else if (strcmp(command, "/v") == 0)
        {
            if (simulated == 0)
            {
                Display(stocks);
            }
            else
            {
                Display_2(stocks);
            }
        }
        else if (strcmp(command, "/d") == 0)
        {
            Deposit(User_ptr);
        }
        else if (strcmp(command, "/w") == 0)
        {
            Withdraw(User_ptr);
        }
        else if (strcmp(command, "/end") == 0)
        {
            printf("\n Thank you for being an Investor!");
            user_active == 0;
            break;
        }
        else
        {
            printf("\n Invalid Command");
        }
        /*printf("Enter your age: ");
        scanf("%d",&User_ptr->age);
        printf("\n");*/
}
}
// User Initilaization Function
void Initilize_User(struct User *User_ptr)
{
    printf("Enter your Username: ");
    fgets(User_ptr->name, sizeof(User_ptr->name), stdin);
    printf("Welcome to the Stock Market, ");
    puts(User_ptr->name);
    
check:
    printf("Set a 4-digit pin: ");
    fgets(User_ptr->password, sizeof(User_ptr->password), stdin);
    if (strlen(User_ptr->password) != 4)
    {
        printf("The pin must contain 4 digits!\n");
        goto check;
    }
    for (int i = 0; i < 4; i++)
    {
        if (User_ptr->password[i] < '0' || User_ptr->password[i] > '9')
        {
            printf("The pin must only contain numerical values!\n");
            goto check;
        }
    }
    printf("Your PIN has been set!\n");

    printf("Enter the amount you wish to Deposit in your trading account: ");
    scanf("%f", &User_ptr->balance);
    printf("Your balance is %.2f", User_ptr->balance);
}

// Stocks Displaying Function
void Display(struct Stock stocks[20])
{
    printf("\n Name \t\t\t\tSymbol \t \t Current Stock Price");
    for (int i = 0; i <= 19; i++)
    {
        if (i == 11 || i == 18)
        {
            printf("\n %s   \t%s \t\t %.2f", stocks[i].name, stocks[i].symbol, stocks[i].current_price);
            printf("\n");
            continue;
        }
        printf("\n %s   \t%s \t\t %.2f", stocks[i].name, stocks[i].symbol, stocks[i].current_price);
        printf("\n");
    }
    printf("Note: The value of the stocks won't change untill you simulate the stock market at least once!\n");
}

void Display_2(struct Stock stocks[20])
{
    float dev = 0;
    printf("\n Name \t\t\t\tSymbol \t\t Past Price \t --> \t Stock Price \t Deviation");
    for (int i = 0; i <= 19; i++)
    {
        if (i == 11 || i == 18 || i == 2 || i == 10 || i == 14 || i == 16 || i == 17)
        {
            dev = stocks[i].current_price - stocks[i].past_price;
            printf("\n %s   \t%s \t\t %.2f  \t --> \t %.2f    \t %.2f", stocks[i].name, stocks[i].symbol, stocks[i].past_price, stocks[i].current_price, dev);
            printf("\n");
            continue;
        }
        printf("\n");
        dev = stocks[i].current_price - stocks[i].past_price;
        printf("\n %s   \t%s \t\t %.2f\t --> \t %.2f \t %.2f\n", stocks[i].name, stocks[i].symbol, stocks[i].past_price, stocks[i].current_price, dev);
    }
}
// Portfolio Displaying Function
void Portfolio(struct Stock stocks[20], struct User *User_ptr)
{
    float hold = 0;
    float dev = 0;
    printf("Currently viewing the portfolio of: ");
    puts(User_ptr->name);
    printf("\n");
    printf("Stocks Owned: \n");
    printf("\n Name \t\t\t\tSymbol \t\t Past Price \t --> \t Stock Price \t Deviation \t Stocks Owned");
    for (int i = 0; i <= 19; i++)
    {
        if (stocks[i].user_holding > 0)
        {
            if (i == 11 || i == 18 || i == 2 || i == 10 || i == 14 || i == 16 || i == 17)
            {
                dev = stocks[i].current_price - stocks[i].past_price;
                printf("\n %s   \t%s \t\t %.2f  \t --> \t %.2f    \t %.2f  \t %d", stocks[i].name, stocks[i].symbol, stocks[i].past_price, stocks[i].current_price, dev, stocks[i].user_holding);
                hold = hold + (stocks[i].user_holding * stocks[i].current_price);
                printf("\n");
                continue;
            }
            printf("\n");
            dev = stocks[i].current_price - stocks[i].past_price;
            printf("\n %s   \t%s \t\t %.2f\t --> \t %.2f \t %.2f  \t %d", stocks[i].name, stocks[i].symbol, stocks[i].past_price, stocks[i].current_price, dev, stocks[i].user_holding);
            hold = hold + (stocks[i].user_holding * stocks[i].current_price);
            printf("\n");
        }
    }
    User_ptr->current_holding = hold;
    printf("\nCurrent Holding: %.2f \n", User_ptr->current_holding);
    printf("Available Balance: %.2f \n", User_ptr->balance);
}
// Stocks Buying Function
void Buy(struct Stock stocks[20], struct User *User_ptr)
{
    char s_buy[10];
    float s_price;
    int i = 0;
    int num_s;
    char pin[5];
check2:
    printf("Enter the *Symbol* of the stock you wish to buy: ");
    scanf("%s", &s_buy);
    for (i = 0; i <= 19; i += 1)
    {
        if (strcmp(strupr(s_buy), stocks[i].symbol) == 0)
        {
            s_price = stocks[i].current_price;
            break;
        }
        else if (i == 19)
        {
            printf("Please Enter a valid symbol!\n");
            goto check2;
        }
    }
check3:

    printf("Enter *number* of stocks you wish to buy: ");
    scanf("%d", &num_s);
    if (num_s <= 0)
    {
        num_s = 0;
        goto check3;
    }
    else if (User_ptr->balance < num_s * s_price)
    {
        printf("Insufficient Balance!");
        goto check2;
    }
    else
    {
        printf("Enter your 4-digit pin: ");
        scanf("%s", &pin);
        if (strcmp(pin, User_ptr->password) == 0)
        {
            printf("Stock Purchased Sucessfully!\n");
            User_ptr->balance = User_ptr->balance - (num_s * s_price);
            stocks[i].user_holding += num_s;
            printf("Available Balance: %.2f", User_ptr->balance);
        }
        else
        {
            printf("Invalid Pin\nPlease Try Again!");
        }
    }
}
// Stock Selling Function
void Sell(struct Stock stocks[20], struct User *User_ptr)
{
    char s_buy[10];
    float s_price;
    int num_s;
    char pin[5];

check4:
    printf("Enter the *Symbol* of the stock you wish to sell: ");
    scanf("%s", &s_buy);
    int i = 0;
    for (i = 0; i <= 19; i += 1)
    {
        if (strcmp(strupr(s_buy), stocks[i].symbol) == 0)
        {
            s_price = stocks[i].current_price;
            break;
        }
        else if (i == 19)
        {
            printf("Please Enter a valid symbol!\n");
            goto check4;
        }
    }
check5:
    printf("Enter *number* of stocks you wish to sell: ");
    scanf("%d", &num_s);
    if (num_s <= 0)
    {
        num_s = 0;
        goto check5;
    }
    else if (stocks[i].user_holding < num_s)
    {
        printf("You don't have those many stocks");
        goto check4;
    }
    else
    {
        printf("Enter your 4-digit pin: ");
        scanf("%s", &pin);
        if (strcmp(pin, User_ptr->password) == 0)
        {
            printf("Stock Sold Sucessfully!\n");
            User_ptr->balance = User_ptr->balance + (num_s * s_price);
            stocks[i].user_holding = stocks[i].user_holding - num_s;
            printf("Available Balance: %.2f", User_ptr->balance);
        }
        else
        {
            printf("Invalid Pin\nPlease Try Again!");
        }
    }
}

// Stock Market Simulation Function
void Simulate(struct Stock stocks[20])
{
    int n_days;
    int loss_percentage;
    int profit_percentage;

    printf("For how many days would you like to simulate the stock market: ");
    scanf("%d", &n_days);

    printf("\nSimulating: [");
    for (int i = 0; i < 20; i++)
    {
        printf("#");
        fflush(stdout);
        usleep(100000); // Adjust delay
    }
    Initilize_Stocks_2(stocks);
    srand(time(0));
    for (int j = 0; j <= n_days; j++)
    {
        for (int k = 0; k <= 19; k++)
        {
            stocks[k].past_price = stocks[k].current_price;
            int profit_or_loss = rand() % 2;
            if (profit_or_loss == 0)
            {
                loss_percentage = (rand() % 3) + 5;
                // stocks[k].deviation = 0;
                stocks[k].current_price = stocks[k].current_price - (stocks[k].past_price * loss_percentage / 100);
            }

            else
            {
                profit_percentage = (rand() % 3) + 5;
                // stocks[k].deviation = 0;
                stocks[k].current_price = stocks[k].current_price + (stocks[k].past_price * profit_percentage / 100);
            }
        }
    }
    printf("] Done!\n\a");
    simulated = 1;
}
// Withdraw Funds Function
void Withdraw(struct User *User_ptr)
{
    float w_amount;
    char pin[5];
amt_check:
    printf("\nPlease Enter the amount you wish to withdraw: ");
    scanf("%f", &w_amount);
    if (w_amount > User_ptr->balance)
    {
        printf("\nInsufficient Funds!");
        goto amt_check;
    }
    else if (w_amount <= 0)
    {
        printf("\nPlease enter an amount greater than 0");
        goto amt_check;
    }
    else
    {
    pin_check:
        printf("Enter your 4-digit pin: ");
        scanf("%s", &pin);
        if (strcmp(pin, User_ptr->password) == 0)
        {
            User_ptr->balance = User_ptr->balance - w_amount;
            printf("\nFunds Withdrawn Sucessfully!");
            printf("\nAvailable Balance: %.2f", User_ptr->balance);
        }
        else
        {
            printf("\nInvalid Pin\nPlease Try Again!");
            goto pin_check;
        }
    }
}

// Deposit Funds Function
void Deposit(struct User *User_ptr)
{
    float d_amount;
    char pin[5];
amt_check:
    printf("\nPlease Enter the amount you wish to deposit: ");
    scanf("%f", &d_amount);
    if (d_amount <= 0)
    {
        printf("\nPlease enter an amount greater than 0");
        goto amt_check;
    }
    else
    {
    pin_check:
        printf("Enter your 4-digit pin: ");
        scanf("%s", &pin);
        if (strcmp(pin, User_ptr->password) == 0)
        {
            User_ptr->balance = User_ptr->balance + d_amount;
            printf("\nFunds Deposited Sucessfully!");
            printf("\nAvailable Balance: %.2f", User_ptr->balance);
        }
        else
        {
            printf("\nInvalid Pin\nPlease Try Again!");
            goto pin_check;
        }
    }
}

// Stocks Initilization Function
void Initilize_Stocks(struct Stock stocks[20])
{
    stocks[0].name = "APPLE               ";
    stocks[0].symbol = "AAPL";
    stocks[0].current_price = 1707.20;
    stocks[0].past_price = 1707.20;
    stocks[0].user_holding = 0;

    stocks[1].name = "MICROSOFT           ";
    stocks[1].symbol = "MSFT";
    stocks[1].current_price = 3300.00;
    stocks[1].past_price = 3300.00;
    stocks[1].user_holding = 0;

    stocks[2].name = "NVIDIA              ";
    stocks[2].symbol = "NVDA";
    stocks[2].current_price = 949.40;
    stocks[2].past_price = 949.40;
    stocks[2].user_holding = 0;

    stocks[3].name = "AMAZON              ";
    stocks[3].symbol = "AMZN";
    stocks[3].current_price = 1576.30;
    stocks[3].past_price = 1576.30;
    stocks[3].user_holding = 0;

    stocks[4].name = "BERKSHIRE HATHWAY   ";
    stocks[4].symbol = "BRK-B";
    stocks[4].current_price = 4496.50;
    stocks[4].past_price = 4496.50;
    stocks[4].user_holding = 0;

    stocks[5].name = "ALPHABET            ";
    stocks[5].symbol = "GOOG";
    stocks[5].current_price = 1369.50;
    stocks[5].past_price = 1369.50;
    stocks[5].user_holding = 0;

    stocks[6].name = "META                ";
    stocks[6].symbol = "META";
    stocks[6].current_price = 4643.60;
    stocks[6].past_price = 4643.60;
    stocks[6].user_holding = 0;

    stocks[7].name = "TESLA               ";
    stocks[7].symbol = "TSLA";
    stocks[7].current_price = 2139.80;
    stocks[7].past_price = 2139.80;
    stocks[7].user_holding = 0;

    stocks[8].name = "TOYOTA              ";
    stocks[8].symbol = "TM";
    stocks[8].current_price = 1452.70;
    stocks[8].past_price = 1452.70;
    stocks[8].user_holding = 0;

    stocks[9].name = "VISA                ";
    stocks[9].symbol = "V";
    stocks[9].current_price = 2881.90;
    stocks[9].past_price = 2881.90;
    stocks[9].user_holding = 0;

    stocks[10].name = "TATA STEEL          ";
    stocks[10].symbol = "TTSL";
    stocks[10].current_price = 133.42;
    stocks[10].past_price = 133.42;
    stocks[10].user_holding = 0;

    stocks[11].name = "CANARA BANK         ";
    stocks[11].symbol = "CANBK";
    stocks[11].current_price = 90.53;
    stocks[11].past_price = 90.53;
    stocks[11].user_holding = 0;

    stocks[12].name = "INFOSYS             ";
    stocks[12].symbol = "INFY";
    stocks[12].current_price = 1416.80;
    stocks[12].past_price = 1416.80;
    stocks[12].user_holding = 0;

    stocks[13].name = "RELIANCE INDUSTRIES ";
    stocks[13].symbol = "REL";
    stocks[13].current_price = 1220.00;
    stocks[13].past_price = 1220.00;
    stocks[13].user_holding = 0;

    stocks[14].name = "TATA MOTORS         ";
    stocks[14].symbol = "TTMR";
    stocks[14].current_price = 596.00;
    stocks[14].past_price = 596.00;
    stocks[14].user_holding = 0;

    stocks[15].name = "HDFC BANK           ";
    stocks[15].symbol = "HDFC";
    stocks[15].current_price = 1805.20;
    stocks[15].past_price = 1805.20;
    stocks[15].user_holding = 0;

    stocks[16].name = "BHARAT ELECTRONICS  ";
    stocks[16].symbol = "BEL";
    stocks[16].current_price = 285.30;
    stocks[16].past_price = 285.30;
    stocks[16].user_holding = 0;

    stocks[17].name = "STATE BANK OF INDIA ";
    stocks[17].symbol = "SBI";
    stocks[17].current_price = 753.85;
    stocks[17].past_price = 753.85;
    stocks[17].user_holding = 0;

    stocks[18].name = "PUNJAB NATIONAL BANK";
    stocks[18].symbol = "PNB";
    stocks[18].current_price = 96.08;
    stocks[18].past_price = 96.08;
    stocks[18].user_holding = 0;

    stocks[19].name = "ICICI BANK          ";
    stocks[19].symbol = "ICICI";
    stocks[19].current_price = 1312.05;
    stocks[19].past_price = 1312.05;
    stocks[19].user_holding = 0;

}

void Initilize_Stocks_2(struct Stock stocks[20])
{
    stocks[0].name = "APPLE               ";
    stocks[0].symbol = "AAPL";

    stocks[1].name = "MICROSOFT           ";
    stocks[1].symbol = "MSFT";

    stocks[2].name = "NVIDIA              ";
    stocks[2].symbol = "NVDA";

    stocks[3].name = "AMAZON              ";
    stocks[3].symbol = "AMZN";

    stocks[4].name = "BERKSHIRE HATHWAY   ";
    stocks[4].symbol = "BRK-B";

    stocks[5].name = "ALPHABET            ";
    stocks[5].symbol = "GOOG";

    stocks[6].name = "META                ";
    stocks[6].symbol = "META";

    stocks[7].name = "TESLA               ";
    stocks[7].symbol = "TSLA";

    stocks[8].name = "TOYOTA              ";
    stocks[8].symbol = "TM";

    stocks[9].name = "VISA                ";
    stocks[9].symbol = "V";

    stocks[10].name = "TATA STEEL          ";
    stocks[10].symbol = "TTSL";

    stocks[11].name = "CANARA BANK         ";
    stocks[11].symbol = "CANBK";

    stocks[12].name = "INFOSYS             ";
    stocks[12].symbol = "INFY";

    stocks[13].name = "RELIANCE INDUSTRIES ";
    stocks[13].symbol = "REL";

    stocks[14].name = "TATA MOTORS         ";
    stocks[14].symbol = "TTMR";

    stocks[15].name = "HDFC BANK           ";
    stocks[15].symbol = "HDFC";

    stocks[16].name = "BHARAT ELECTRONICS  ";
    stocks[16].symbol = "BEL";

    stocks[17].name = "STATE BANK OF INDIA ";
    stocks[17].symbol = "SBI";

    stocks[18].name = "PUNJAB NATIONAL BANK";
    stocks[18].symbol = "PNB";

    stocks[19].name = "ICICI BANK          ";
    stocks[19].symbol = "ICICI";

}
