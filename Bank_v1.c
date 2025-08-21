#include <stdio.h>
#ifdef _WIN32
    #include <windows.h>
    #define sleep_ms(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define sleep_ms(ms) usleep((ms) * 1000)   // THIS PART TAKEN FROM GPT
#endif
#ifdef _WIN32
    #include <conio.h>
    #define press_any_key() { printf("\nPress any key to continue..."); getch(); }
#else
    #define press_any_key() { printf("\nPress Enter to continue..."); while (getchar()!='\n'); getchar(); }
#endif // THIS PART TAKEN FROM GPT


int main(){
    float balance = 0;
    float deposit = 0;
    float withdraw = 0;
    int option = 0;
    int i = 0;
    while (i != 1)
    {
        int delay = 250;
        printf("\n=== Welcome to the Bank ===\n");
        sleep_ms(delay*3);
        printf("Press 1 for Depositing Money\n");sleep_ms(delay);
        printf("Press 2 for Checking Balance\n");sleep_ms(delay);
        printf("Press 3 for Withdrawing Money\n");sleep_ms(delay);
        printf("Press 4 to exit\n");
        sleep_ms(delay*3);
        printf("Enter the option: ");
        scanf("%d", &option);
        while (getchar() != '\n'); 

        switch (option)
        {
        case 1:
            printf("How much money u wanna add? - $");
            scanf("%f", &deposit);
            if (deposit >= 0){
                balance = balance + deposit;
                printf("Balance Added Successfully! \nCurrent Balance: $%.2f", balance);
            }
            else{
                printf("Invalid Request");
            }
            press_any_key();
            break;

        case 2:
            printf("Current Balance: $%.2f", balance);
            press_any_key();
            break;

        case 3:
            if (balance > 0){
                printf("How much money u wanna withdraw? - $");
                scanf("%f", &withdraw);  
                if (withdraw > 0 && withdraw <= balance) {
                    balance = balance - withdraw;            
                    printf("Money Withdrawn Successfully! \nCurrent Balance: $%.2f", balance);
                } 
                else if (withdraw > balance){
                    printf("Invalid Withdraw Request Insufficient Balance");
                }
                else{
                    printf("Invalid Withdraw Request Negative Amount");
                }
            }
            else {
                printf("Invalid Request, Balance = $0");
            }
            press_any_key();
            break;

        case 4:
            printf("Thank you for being our coustomer, Visit Again");
            i = 1;
            break;
        default:
            printf("Invalid input");
            press_any_key();
            break;

        }
    }
    
    return 0;
}