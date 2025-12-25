#include "Person.h"

Person::Person()
{
    firstName[0] = lastName[0] = gender[0] = '\0';
}
//добавила комментарий
Person::~Person() {}

istream& operator>>(istream& in, Person& p)
{
    cout << "Enter first name: ";
    in.getline(p.firstName, SIZE_N);
    cout << "Enter last name: ";
    in.getline(p.lastName, SIZE_N);
    cout << "Enter gender: ";
    in.getline(p.gender, SIZE_N);
    return in;
}
ostream& operator<<(ostream& out, const Person& p)
{
    out << setw(15) << p.firstName
        << setw(15) << p.lastName
        << setw(10) << p.gender;
    return out;
}

void Person::getFirstName(char* buffer) const
{
    strcpy_s(buffer, SIZE_N, firstName);
}

void Person::setFirstName(const char* val)
{
    strncpy_s(firstName, SIZE_N, val, _TRUNCATE);
}

void Person::getLastName(char* buffer) const
{
    strcpy_s(buffer, SIZE_N, lastName);
}

void Person::setLastName(const char* val)
{
    strncpy_s(lastName, SIZE_N, val, _TRUNCATE);
}

void Person::getGender(char* buffer) const
{
    strcpy_s(buffer, 10, gender);
}

void Person::setGender(const char* val)
{
    strncpy_s(gender, 10, val, _TRUNCATE);
}

Person& Person::operator=(const Person& other)
{
    if (this != &other)
    {
        strncpy_s(firstName, SIZE_N, other.firstName, _TRUNCATE);
        strncpy_s(lastName, SIZE_N, other.lastName, _TRUNCATE);
        strncpy_s(gender, 10, other.gender, _TRUNCATE);
    }
    return *this;
}