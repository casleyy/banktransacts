#include <iostream>
using namespace std;

//10 recent transaction of user w/ type and value
//nside what iis shown in transaction

struct History {
    string type;
    float value;
};

//array named Transactions for showing history
const int TransactionHistory = 10; //10 recent
History Transactions[TransactionHistory]; //array using struct inside
int HistoryCount = 0;



void DisplayMenu();
void CheckBalance(float &basemon, char &choose, int &attemptscheck);
void DepositAmount(float &deposit, float &basemon, char &choose, int &attemptsdeposit);
void WithdrawAmount(float &withdraw, float &basemon, char &choose, int &attemptswithdraw);
void ChooseMenu(char &choose, float &deposit, float &withdraw, float &basemon, int &attemptscheck, int &attemptsdeposit, int &attemptswithdraw, char &req );

//amount of attempts

int main()
{
    float basemon = 5000;
    char choose;
    float deposit = 0;
    float withdraw = 0;

    char newuser;
    int use = 1;

    char req;

    int attemptswithdraw=0;
    int attemptsdeposit=0;
    int attemptscheck=0;



    cout << "Hello, Dear user!\n\n";

    while (use  <6) {
        do {
            ChooseMenu(choose, deposit, withdraw, basemon, attemptscheck, attemptsdeposit, attemptswithdraw, req);

            cout << "\n\nIs another user gonna order? (Y/N): ";
            cin >> newuser;
            system("cls");

        } while (newuser == 'Y' || newuser == 'y');
        use++;
    }
     cout << "\n\n No more users can use this... Thank you for using our service! Goodbye!\n\n";
     system("pause");
    return 0;
}

void DisplayMenu() {
    cout << "- - - -[MAIN MENU]- - - -\n"
        << "A.\tCheck Bank Balance\n"
        << "B.\tDeposit Money\n"
        << "C.\tWithdraw Money\n"
        << "D.\tExit\n";
}

void ChooseMenu(char &choose, float &deposit, float &withdraw, float &basemon, int &attemptscheck, int &attemptsdeposit, int &attemptswithdraw, char &req) {
    do {
        DisplayMenu();
        cout << "\n\nWhat would you like to do: ";
        cin >> choose;
        switch (toupper(choose)) {
        case 'A':
            CheckBalance(basemon, choose, attemptscheck);
            break;
        case 'B':
            DepositAmount(deposit, basemon, choose, attemptsdeposit );
            break;
        case 'C':
            WithdrawAmount(withdraw, basemon, choose, attemptswithdraw);
            break;
        case 'D':
            system("cls");
                cout << "- - -[EXIT + SUMMARY]- - -\n";
                cout << "Amount of times you checked your balances: " << attemptscheck;
                cout << "\nAmount of times you deposited: " << attemptsdeposit;
                cout << "\nAmount of times you have withdrawn: " << attemptswithdraw;

                do {
                    cout << "\n\nWould you like to see your transaction history? (Y/N): ";
                    cin >> req;

                    switch (toupper(req)) {
                    case 'Y':
                        system("cls");
                        cout << "- - -[TRANSACTION HISTORY]- - -\n";

                        //no transactiions

                        if (HistoryCount == 0) {
                            cout << "\n\nNo transactions were made!";
                        }
                        else{
                            //make array
                            for (int i = 0; i < HistoryCount; i++) {
                                int index = i % TransactionHistory;
                                cout << Transactions[index].type << ": Php " << Transactions[index].value << "\n\n";
                            }
                        }

                        system("pause");
                        system("cls");
                        break;
                    case 'N':
                        cout << "\n\nAlright ! Thank you for cooperating with us !\n\n";
                        system("pause");
                        system("cls");
                        break;
                    default:
                        cout << "\n\nInvalid response! Try again !";
                            break;
                    }

                } while (req != 'Y' && req != 'y' && req != 'N' && req != 'n');

               
            break;
        default:
            cout << "\nThat is not a valid response! Please try again!";
            break;
        }
    } while (toupper(choose) != 'D');
}

// DEPOSIT PART
void DepositAmount(float &deposit, float &basemon, char &choose, int &attemptsdeposit) {
    system ("cls");
    cout << "- - - [DEPOSIT]- - -"
        << "\nPlease enter the amount you would like to deposit: ";
    cin >> deposit;

    cout << "\n\nYou have decided to deposit the following amount: Php " << deposit;
    if (deposit >= 5000) {
        cout << "\n\nSorry! We don't accept transactions exceeding Php 5000. Please try again!";
    }
    else if (deposit <= 0) {
        cout << "\n\nThat is not a valid number! Please try again!\n\n";
    }
    else {
        cout << "\n\nAlright! Depositing Php " << deposit << " to your account now...\n";
        basemon += deposit;
        cout << "Your balance is now: Php " << basemon << "\n\n";

        

        //indexing in the history
        Transactions[HistoryCount % TransactionHistory] = { "Deposit", deposit };
        HistoryCount++;
    }


    attemptsdeposit++;  

    system("pause");
    system("cls");
}

// WITHDRAW PART
void WithdrawAmount(float &withdraw, float &basemon, char &choose, int &attemptswithdraw) {
    system("cls");
    cout << "- - - [WITHDRAW]- - -"
        << "\nPlease enter the amount you would like to withdraw: ";
    cin >> withdraw;

    cout << "\n\nYou have decided to withdraw the following amount: Php " << withdraw;
    if (withdraw >= 5000) {
        cout << "\n\nSorry! We don't accept transactions exceeding Php 5000. Please try again!";
    }
    else if (withdraw <= 0) {
        cout << "\n\nThat is not a valid number! Please try again!\n\n";
    }
    else if (withdraw > basemon) {
        cout << "This is greater than the money in your account! Please try again!\n\n";
    }
    else {
        cout << "\n\nAlright! Withdrawing Php " << withdraw << " from your account now...\n";
        basemon -= withdraw;
        cout << "Your balance is now: Php " << basemon << "\n\n";

        //indexing in the history
        Transactions[HistoryCount % TransactionHistory] = { "Withdraw", withdraw };
        HistoryCount++;
    }

    attemptswithdraw++; 

    system("pause");  
    system("cls"); 
}

// CHECK BALANCE  
void CheckBalance(float &basemon, char &choose, int &attemptscheck) {
    system("cls");
    cout << "- - - [CHECK BALANCE]- - -"
        << "\nAs of right now, your balance is: Php " << basemon << "\n";

    attemptscheck++;

    system("pause"); 
    system("cls"); 
}