#include <iostream>

enum Permissions
{
    ADMINISTRATOR = 1,
    USER_LOCAL
};

class UserKeys
{
public:
    UserKeys();
    ~UserKeys();
    void SetCodeUser(std::string _codeUser);
    std::string GetCodeUser();
    bool SetPassword(std::string _password);
    std::string GetPassword();
    void SetTypeAcount(Permissions _typeAcount);
    Permissions GetTypeAcount();

private:
    Permissions typeAcount;
    char codeUser[14];
    char password[8];
};
