#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "../lib/ftr.hpp"
#include "Employees.hpp"
#include "userKeys.hpp"
//#include "Registros.hpp"
#define FILE_STAFF "../data/regTrab.dat"
#define FILE_USER "../data/regUser.dat"

using namespace ftr;

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
