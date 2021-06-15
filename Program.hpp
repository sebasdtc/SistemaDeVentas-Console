#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "futil.hpp"
#include "Employees.hpp"
#include "userKeys.hpp"
//#include "Registros.hpp"
#define FILE_STAFF "regTrab.dat"
#define FILE_USER "regUser.dat"

using namespace futil;

void Program();

void SystemMenu();
void RegisterPersonal();

void Warehouse();
void sales();
void buy();

uint16_t ReadLine();
void ErrorMessage(const char *text);

bool ExistUser(UserKeys _uKey);
template <class T>
bool SaveDataRegister(T t, const char *text);
