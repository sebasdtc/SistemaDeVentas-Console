#pragma once

#include <iostream>
#include <string>
#include <thread>
#include "date.hpp"

#define SIZE_MAX_CODE 14
#define SIZE_MAX_DOCU 11
#define SIZE_MAX_NAME 51

class Employees
{
public:
    // Constructores
    Employees(std::string _name, std::string _lastName, std::string _direction, std::string _document);
    ~Employees();
    // setter y getter
    void SetDateOfBirth(uint16_t _day, uint16_t _month, uint16_t _year);
    Date GetDateOfBirth();
    void SetName(std::string _name);
    std::string GetName();
    void SetLastName(std::string _lastName);
    std::string GetLastName();
    void SetDirection(std::string _direction);
    std::string GetDirection();
    void SetDocument(std::string _document);
    std::string GetDocument();
    void SetCodeUser();
    std::string GetCode();
    bool SaveSatffRegister();

private:
    Date dateOfBirth{0};
    char codUser[SIZE_MAX_CODE];
    char document[SIZE_MAX_DOCU];
    char name[SIZE_MAX_NAME];
    char lastName[SIZE_MAX_NAME];
    char direction[SIZE_MAX_NAME];
};