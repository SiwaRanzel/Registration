#include <iostream>
#include <fstream>

void writetofile(std::string username);
void logIn(std::string username);
void registerme();

int choice;
bool registered;
int confirmation;
std::string username;
std::string password;
std::string password2;

// STILL IN PROGRESS

int main()
{
    std::cout << "Welcome__To__The__Raniverse\n";
    while (registered = true)
    {
        std::cout << "\nWould you like to login or register\n"
                  << "[1] Login\n"
                  << "[2] Register\n"
                  << "[3] Exit\n";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            logIn(username);
            break;
        case 2:
            registerme();
            break;
        case 3:
            std::cout << "Thanks for visiting";
            return 0;
            break;
        default:
            break;
        }
    }
    return 0;
}
void writetofile(std::string username)
{
    std::ofstream writefile;
    std::string file = username + ".txt";
    writefile.open(file.c_str());
    writefile << password;
    writefile.close();
}

void logIn(std::string username)
{
    std::cout << "Please enter your username: ";
    std::cin >> username;
    std::ifstream inputFile(username + ".txt");
    if (inputFile.is_open())
    {
        std::string line;
        std::getline(inputFile, line);
        inputFile.close();
        std::cout << "Please enter your password: ";
        std::cin >> password;
        if (password == line)
        {
            std::cout << "You are logged in " << username << "\n";
        }
        else
        {
            std::cout << "Incorrect Password\n"
                      << "You are an imposter!!!\n";
        }
    }
    else
    {
        std::cout << "This username does not exist\n"
                  << std::endl;
    }
}

void registerpassword()
{
    std::cout << "Please enter the password: ";
    std::cin >> password;
    std::cout << "Please renter your password: ";
    std::cin >> password2;
    if (password == password2)
    {
        writetofile(username);
    }
    else
    {
        std::cout << "Sorry invalid\n";
        registerpassword();
    }
}

void registerme()
{
    std::cout << "Please enter your username: ";
    std::cin >> username;
    std::ifstream inputFile(username + ".txt");
    if (inputFile.is_open())
    {
        inputFile.close();
        std::cout << "This username name exists: login or register with a new username\n";
    }
    else
    {
        std::cout << "Username - " << username << "\n"
                  << "Confirm?\n"
                  << "[1] Yes\n"
                  << "[2] No\n";
        std::cin >> confirmation;
        if (confirmation == 1)
        {
            registerpassword();
            std::cout << "You have succefully created your account\n";
        }
        else
        {
            std::cout << "Sorry invalid input, Please try again\n";
            registerme();
        }
    }
}