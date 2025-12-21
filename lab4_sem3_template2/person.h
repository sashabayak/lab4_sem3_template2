#pragma once
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

const int SIZE_N = 40;

class Person
{
protected:
    char firstName[SIZE_N];
    char lastName[SIZE_N];
    char gender[SIZE_N];

public:
    Person();
    virtual ~Person();

    friend istream& operator>>(istream& in, Person& p);
    friend ostream& operator<<(ostream& out, const Person& p);

    virtual void printHeader() const = 0;

    void getFirstName(char* buffer) const;
    void setFirstName(const char* val);

    void getLastName(char* buffer) const;
    void setLastName(const char* val);

    void getGender(char* buffer) const;
    void setGender(const char* val);

    Person& operator=(const Person& other);
};
#pragma once
