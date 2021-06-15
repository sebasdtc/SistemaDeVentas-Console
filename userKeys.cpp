#include "userKeys.hpp"

UserKeys::UserKeys() : codeUser(""), password(""), typeAcount(USER_LOCAL)
{
}

UserKeys::~UserKeys()
{
}

void UserKeys::SetCodeUser(std::string _codeUser) { std::char_traits<char>::copy(codeUser, _codeUser.c_str(), 14); }
std::string UserKeys::GetCodeUser() { return codeUser; }
bool UserKeys::SetPassword(std::string _password)
{
    if (_password.length() < 6 || _password.length() > 8)
        return false;
    std::char_traits<char>::copy(password, _password.c_str(), 9);
    return true;
}
std::string UserKeys::GetPassword() { return password; }

void UserKeys::SetTypeAcount(Permissions _typeAcount) { typeAcount = _typeAcount; }
Permissions UserKeys::GetTypeAcount() { return typeAcount; }