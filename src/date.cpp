#include "../include/date.hpp"

Date::Date()
{
    time_t now = time(nullptr);
    auto dateNow = *localtime(&now);
    day = dateNow.tm_mday;
    month = dateNow.tm_mon;
    year = dateNow.tm_year;
}

Date::Date(uint16_t _value) : day(_value), month(_value), year(_value)
{}

Date::~Date()
{}

std::string Date::GetDate()
{
    time_t now = time(nullptr);
    auto dateNow = *localtime(&now);
    char buf[80];
    strftime(buf, sizeof(buf), "%d-%m-%Y %X", &dateNow);
    return buf;
}

void Date::SetDay(uint16_t _day) { day = _day; }
uint16_t Date::GetDay() { return day; }

void Date::SetMonth(uint16_t _month) { month = _month; }
uint16_t Date::GetMonth() { return month + 1; }

void Date::SetYear(uint16_t _year) { year = _year; }
uint16_t Date::Getyear() { return year + 1900; }