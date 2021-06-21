#include <iostream>
#include <iomanip>
#include "../include/Program.hpp"

// claves creadas eb47931526 gal22v10
// claves creadas D70336727 sebasdtc

int main()
{
    UserKeys userKey;
    std::string user, password;
    do
    {
        std::cout << "Usuario: ";
        std::cin >> user;
        std::cout << "Contraseña: ";
        std::cin >> password;
        userKey.SetCodeUser(user);
        userKey.SetPassword(password);
        if (ExistUser(userKey))
            Program();
        else
            ErrorMessage("Usuario y contraseña incorrectas");
    } while (true);
    return 0;
}