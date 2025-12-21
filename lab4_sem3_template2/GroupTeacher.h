#pragma once
#include "Teacher.h"

const int MAX_GROUPS = 5;

class GroupTeacher : public Teacher
{
    char subject[SIZE_N];
    char students[MAX_GROUPS][SIZE_N];
    int studentCount;

public:
    GroupTeacher();

    friend istream& operator>>(istream& in, GroupTeacher& gt);
    friend ostream& operator<<(ostream& out, const GroupTeacher& gt);

    static bool compareByFirstName(const GroupTeacher& a, const GroupTeacher& b);
    static bool compareByLastName(const GroupTeacher& a, const GroupTeacher& b);
    static bool compareByGradeOrHours(const GroupTeacher& a, const GroupTeacher& b);
    static bool compareBySubject(const GroupTeacher& a, const GroupTeacher& b);
    static bool compareByStudentCount(const GroupTeacher& a, const GroupTeacher& b);

    void printHeader() const override;

    void getSubject(char* buffer) const;
    void setSubject(const char* val);

    int getStudentCount() const;
    void setStudentCount(int val);

    void getStudent(int index, char* buffer) const;
    void setStudent(int index, const char* val);

    GroupTeacher& operator=(const GroupTeacher& other);

    bool operator==(const GroupTeacher& other) const;
    void virtual editGroupTeacher();

    static auto getComparator() -> bool (*)(const GroupTeacher&, const GroupTeacher&);
};
