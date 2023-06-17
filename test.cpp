#include <iostream>
#include <string>

int main()
{
    std::string phoneNumber;
    std::string amount;

    std::cout << "Enter the phone number you want to send money to: ";
    std::getline(std::cin, phoneNumber);

    std::cout << "Enter the amount you want to send: ";
    std::getline(std::cin, amount);

    // Rest of your code here

    return 0;
}
