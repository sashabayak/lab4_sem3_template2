#pragma once
#define SIZE_G 20
#include "Person.h"

class Student : public Person
{

    int grade;


public:
    Student();

    friend istream& operator>>(istream& in, Student& s);
    friend ostream& operator<<(ostream& out, const Student& s);

    void printHeader() const override;

    static auto getComparator() -> bool (*)(const Student&, const Student&);

    int getGrade()const;
    void setGrade(int val);

    static bool compareByFirstName(const Student& a, const Student& b);


    static bool compareByLastName(const Student& a, const Student& b);

    static bool compareByGradeOrHours(const Student& a, const Student& b);

    Student& operator=(const Student& other);

    bool operator==(const Student& other) const;


    void virtual  editStudent();
};

