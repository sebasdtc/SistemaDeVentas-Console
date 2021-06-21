#include "../include/Employees.hpp"

Employees::Employees(std::string _name, std::string _lastName, std::string _direction, std::string _document)
{
    SetName(_name);
    SetLastName(_lastName);
    SetDirection(_direction);
    SetDocument(_document);
    SetCodeUser();
}

Employees::~Employees() {}

// setter y getter
void Employees::SetDateOfBirth(uint16_t _day, uint16_t _month, uint16_t _year)
{
    dateOfBirth.SetDay(_day);
    dateOfBirth.SetMonth(_month);
    dateOfBirth.SetYear(_year);
}
Date Employees::GetDateOfBirth() { return dateOfBirth; } // dateOfBirth

void Employees::SetName(std::string _name)
{
    std::char_traits<char>::copy(name, _name.c_str(), SIZE_MAX_NAME - 1);
}
std::string Employees::GetName() { return name; } // name

void Employees::SetLastName(std::string _lastName)
{
    std::char_traits<char>::copy(lastName, _lastName.c_str(), SIZE_MAX_NAME - 1);
}
std::string Employees::GetLastName() { return lastName; } // lastname

void Employees::SetDirection(std::string _direction)
{
    std::char_traits<char>::copy(direction, _direction.c_str(), SIZE_MAX_NAME - 1);
}
std::string Employees::GetDirection() { return direction; } // direction

void Employees::SetDocument(std::string _document)
{
    std::char_traits<char>::copy(document, _document.c_str(), SIZE_MAX_DOCU - 1);
}
std::string Employees::GetDocument() { return document; } // document

void Employees::SetCodeUser()
{
    std::string tmpStr{""};
    tmpStr = GetName().substr(0, 2) + GetDocument();
    std::char_traits<char>::copy(codUser, tmpStr.c_str(), tmpStr.length() + 1);
}
std::string Employees::GetCode() { return codUser; }