#pragma once
#include "Teacher.h"

const int MAX_STUDENTS = 5;

class SpecialtyTeacher : public Teacher
{
    char subject[SIZE_N];
    char students[MAX_STUDENTS][SIZE_N];
    int studentCount;

public:
    SpecialtyTeacher();

    friend istream& operator>>(istream& in, SpecialtyTeacher& st);
    friend ostream& operator<<(ostream& out, const SpecialtyTeacher& st);

    void printHeader() const override;

    void getSubject(char* buffer) const;
    void setSubject(const char* val);

    int getStudentCount() const;
    void setStudentCount(int val);

    void getStudent(int index, char* buffer) const;
    void setStudent(int index, const char* val);

    SpecialtyTeacher& operator=(const SpecialtyTeacher& other);

    static bool compareByFirstName(const SpecialtyTeacher& a, const SpecialtyTeacher& b);
    static bool compareByLastName(const SpecialtyTeacher& a, const SpecialtyTeacher& b);
    static bool compareByGradeOrHours(const SpecialtyTeacher& a, const SpecialtyTeacher& b);
    static bool compareBySubject(const SpecialtyTeacher& a, const SpecialtyTeacher& b);
    static bool compareByStudentCount(const SpecialtyTeacher& a, const SpecialtyTeacher& b);
    void virtual editSpecialtyTeacher();

    bool operator==(const SpecialtyTeacher& other) const;

    static auto getComparator() -> bool (*)(const SpecialtyTeacher&, const SpecialtyTeacher&);
};

