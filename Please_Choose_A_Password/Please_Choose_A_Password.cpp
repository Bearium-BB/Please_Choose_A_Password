#include <iostream>
#include <regex>
#include <string>
#include <conio.h> 

std::string buildPassword()
{
    std::string password;
	char ch;
    while ((ch = _getch()) != '\r')
    {
        //This has to be inside of the while loop otherwise it will not work properly
        //Something about the variable not being utilized
        //ch = _getch();

        if (ch == '\b') {
            if (password.length() != 0) {
                password.pop_back();
                std::cout << "\b \b";
            }
        }
        else
        {
            password += ch;
            std::cout << '*';
        }
    }
    std::cout << std::endl;
    return password;
}

int main()
{
    std::string password;

    bool isRunning = 1;


    while (isRunning)
    {
        std::cout << "Enter password : ";

        password = buildPassword();

        if (!std::regex_search(password, std::regex("^.{8,}$")))
        {
            std::cout << "Password must be at least 8 characters long." << std::endl;
        }
        else if (!std::regex_search(password, std::regex("[a-z]")))
        {
            std::cout << "Password must contain at least one lowercase letter." << std::endl;
        }
        else if (!std::regex_search(password, std::regex("[A-Z]")))
        {
            std::cout << "Password must contain at least one uppercase letter." << std::endl;
        }
        else if (!std::regex_search(password, std::regex("[0-9]")))
        {
            std::cout << "Password must contain at least one number." << std::endl;
        }
        else
        {
            std::cout << "Confirmation Password." << std::endl;

            while (true) 
            {
                std::cout << "Enter password : ";

                std::string passwordConfirmation = buildPassword();

                if (passwordConfirmation == password) {

                    std::cout << "Password is valid. thank you!" << std::endl;

                    isRunning = 0;

                    break;
                }
                else
                {
                    std::cout << "Try Again." << std::endl;
                    break;
                }
            }
        }
    }


}

//std::isupper(c)
//std::islower(c)
//std::isdigit(c)
//password.length() 
