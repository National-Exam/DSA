#include <iostream>
#include <sstream>
#include <string>

using namespace std;
int sendMoney() {
    cout << "Enter the phone number you want to send money to: ";
    string phoneNumber;
    cin.ignore();
    getline(cin, phoneNumber);
    cout << "Enter the amount you want to send: ";
    string amount;
    getline(cin, amount);
    cout << "Enter your pin: ";
    string pin;
    getline(cin, pin);
    cout << "You have sent " << amount << " to " << phoneNumber << endl;
    return 0;
}

int main() {
    cout << "Please enter ussd: ";    
    string ussd;
    getline(cin, ussd);
    if (ussd == "*182#")
    {
        cout << "choose one of the options from the list below\n";
        cout << "1. Send money\n"
                "2. Buy airtime\n"
                "3. Withdraw\n"
                "4. view balance\n";}
        do
        {        
            int option;
            cin >> option;
            switch (option)
            {
            case 1:
                sendMoney();
                break;
            
            default:
                break;
            }
        
    }
    while (ussd != "exit")
        ;

    return 0;
}