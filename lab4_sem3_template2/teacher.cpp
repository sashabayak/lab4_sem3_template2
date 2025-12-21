#include "Teacher.h"

Teacher::Teacher() : hoursPerDay(0) {}


istream& operator>>(istream& in, Teacher& t)
{
    in >> static_cast<Person&>(t);
    cout << "Enter hours per day: ";
    in >> t.hoursPerDay;
    in.ignore();
    return in;
}

ostream& operator<<(ostream& out, const Teacher& t)
{
    out << static_cast<const Person&>(t)
        << setw(15) << t.hoursPerDay;
    return out;
}



int Teacher::getHoursPerDay() const
{
    return hoursPerDay;
}

void Teacher::setHoursPerDay(int val)
{
    hoursPerDay = val;
}

Teacher& Teacher::operator=(const Teacher& other)
{
    if (this != &other)
    {
        Person::operator=(other);
        hoursPerDay = other.hoursPerDay;
    }
    return *this;
}