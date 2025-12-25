#pragma once
#include "Person.h"

class Teacher : public Person
{
protected:
    int hoursPerDay;

public:
    Teacher();

    friend istream& operator>>(istream& in, Teacher& t);
    friend ostream& operator<<(ostream& out, const Teacher& t);

    int getHoursPerDay() const;
    void setHoursPerDay(int val);

    Teacher& operator=(const Teacher& other);
}; //комментарий