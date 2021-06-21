#pragma once

#include <iostream>
#include <ctime>

class Date
{
public:
    std::string GetDate();
    void SetDay(uint16_t _day);
    uint16_t GetDay();
    void SetMonth(uint16_t _month);
    uint16_t GetMonth();
    void SetYear(uint16_t _year);
    uint16_t Getyear();
    Date();
    Date(uint16_t _value);
    ~Date();
private:
    uint16_t day;
    uint16_t month;
    uint16_t year;
};