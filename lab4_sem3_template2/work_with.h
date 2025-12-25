#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include "Student.h"
#include "SpecialtyTeacher.h"
#include "GroupTeacher.h"
#include "queue.cpp"

using namespace std;

void mainMenu();

template<typename T>
void queueMenu(const string& menuTitle);

