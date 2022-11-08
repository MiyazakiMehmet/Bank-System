#include <iostream>
#include <string>

class Account
{
private:
    int withdraw_limit,deposit_limit,withdraw_value,deposit_value;
public:
    Account(int withdraw_lmt, int deposit_lmt){
        withdraw_limit = withdraw_lmt;
        deposit_limit = deposit_lmt;
    }
    void withdraw_money()
    {
        std::cout << "Please enter a value to withdraw: ";
        std::cin >> withdraw_value;
        if(withdraw_value > withdraw_limit)
            while(true){
                std::cout << "You have surpassed the withdraw limit, please prompt less value: ";
                std::cin >> withdraw_value;
                if(withdraw_value <= withdraw_limit && withdraw_value > 0)
                    break;
                else
                    continue;
            }
        else if(withdraw_value <= 0)
            while(true){
                std::cout << "Please enter a valid value: ";
                std::cin >> withdraw_value;
                if(withdraw_value <= withdraw_limit && withdraw_value > 0)
                    break;
                else
                    continue;
            }
        std::cout << "\nYou have successfully withdrawn " << withdraw_value << " amount of money.\n";
        std::cout << std::endl;
    }
    void deposit_money()
    {
        std::cout << "Please enter a value to deposit ";
        std::cin >> deposit_value;
        if(deposit_value > deposit_limit)
            while(true){
                std::cout << "You have surpassed the deposit limit, please prompt less value: ";
                std::cin >> deposit_value;
                if(deposit_value <= deposit_limit && deposit_value > 0)
                    break;
                else
                    continue;
            }
        else if(deposit_value < deposit_limit)
            while(true){
                std::cout << "Please enter a valid value: ";
                std::cin >> deposit_value;
                if(deposit_value <= deposit_limit && deposit_value > 0)
                    break;
                else
                    continue;
            }
        std::cout << "\nYou have successfully deposited " << withdraw_value << " amount of money.\n";
        std::cout << std::endl;
    }
};

void process_again(void (*again)())
{
    char answer;
    do{
        std::cout << "Do you want to quit or continue to process? Q/C ";
        std::cin >> answer;
    }while(answer != 'Q' && answer != 'C');
    
    if(answer == 'C')
        again();
    else
        std::cout << "\nOkay, see you! " << std::endl;
}

void initial()
{
    int selection = 0;
    Account mehmet(2000,4000);
    std::cout << "\nHello welcome to NPC Bank\n" << std::endl;
    std::cout << "1-) Withdraw\n2-)Deposit" << std::endl;
    std::cout << "\nPlease select option that you want to do: ";
    std::cin >> selection;
    if(selection != 1 && selection != 2){
        do{
            std::cout << "Please enter a valid number: ";
            std::cin >> selection;
        }while(selection != 1 && selection != 2);
    }
    std::cout << std::endl;
    if(selection == 1)
        mehmet.withdraw_money();
    else
        mehmet.deposit_money();
    process_again(&initial);
}

int main(){
    initial();
    
    return 0;
}