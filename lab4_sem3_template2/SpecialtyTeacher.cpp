#include "SpecialtyTeacher.h"

SpecialtyTeacher::SpecialtyTeacher() : studentCount(0)
{
    subject[0] = '\0';
    for (int i = 0; i < MAX_STUDENTS; i++)
        students[i][0] = '\0';
}

istream& operator>>(istream& in, SpecialtyTeacher& st)
{
    in >> static_cast <Teacher&>(st);                                            // ????? ????????? ????? ??? ???????? ?????? Person, ????????? ?????????? ???? SpecialtyTeacher& ? Teacher&. 
    cout << "Enter subject taught (e.g. Piano, Drums): ";
    in.getline(st.subject, SIZE_N);
    cout << "Enter number of students (max " << MAX_STUDENTS << "): ";
    in >> st.studentCount;
    if (st.studentCount > MAX_STUDENTS)
    {
        st.studentCount = MAX_STUDENTS;
    }
    in.ignore();
    for (int i = 0; i < st.studentCount; i++)
    {
        cout << "Enter name of student #" << (i + 1) << ": ";
        in.getline(st.students[i], SIZE_N);
    }
    return in;
}

ostream& operator<<(ostream& out, const SpecialtyTeacher& st)
{
    out << static_cast <const Teacher&>(st)
        << setw(20) << st.subject;
    out << setw(30);
    for (int i = 0; i < st.studentCount; i++)
    {
        out << st.students[i];
        if (i != st.studentCount - 1)
        {
            out << "," << endl << setw(105);
        }
    }
    cout << ".";
    return out;
}

void SpecialtyTeacher::printHeader() const
{
    cout << setw(15) << "First Name"
        << setw(15) << "Last Name"
        << setw(10) << "Gender"
        << setw(15) << "Hours/Day"
        << setw(20) << "Subject"
        << setw(30) << "Students" << endl;
}

void SpecialtyTeacher::getSubject(char* buffer) const
{
    strcpy_s(buffer, SIZE_N, subject);
}

void SpecialtyTeacher::setSubject(const char* val)
{
    strncpy_s(subject, SIZE_N, val, _TRUNCATE);
}

int SpecialtyTeacher::getStudentCount() const
{
    return studentCount;
}

void SpecialtyTeacher::setStudentCount(int val)
{
    if (val <= MAX_STUDENTS)
    {
        studentCount = val;
    }
}

void SpecialtyTeacher::getStudent(int index, char* buffer) const
{
    if (index >= 0 && index < studentCount)
    {
        strcpy_s(buffer, SIZE_N, students[index]);
    }
    else
    {
        buffer[0] = '\0';
    }
}

void SpecialtyTeacher::setStudent(int index, const char* val)
{
    if (index >= 0 && index < studentCount)
    {
        strncpy_s(students[index], SIZE_N, val, _TRUNCATE);
    }
}

SpecialtyTeacher& SpecialtyTeacher::operator=(const SpecialtyTeacher& other)
{
    if (this != &other)
    {
        Teacher::operator=(other);
        strncpy_s(subject, SIZE_N, other.subject, _TRUNCATE);
        studentCount = other.studentCount;
        for (int i = 0; i < studentCount; i++)
        {
            strncpy_s(students[i], SIZE_N, other.students[i], _TRUNCATE);
        }
    }
    return *this;
}

void SpecialtyTeacher::editSpecialtyTeacher()
{
    char buffer[SIZE_N];
    char buffer1[SIZE_N];
    int choice;
    do {
        cout << "\nChoose field to edit:\n";
        cout << "1. First Name\n2. Last Name\n3. Gender\n4. Hours per day\n5. Subject\n6. Students\n0. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1:
            getFirstName(buffer1);
            cout << "First name:" << endl;
            cout << buffer1 << endl;
            cout << "Enter new first name: ";
            cin.getline(buffer, SIZE_N);
            setFirstName(buffer);
            break;
        case 2:
            getLastName(buffer1);
            cout << "Last name:" << endl;
            cout << buffer1 << endl;
            cout << "Enter new last name: ";
            cin.getline(buffer, SIZE_N);
            setLastName(buffer);
            break;
        case 3:
            getGender(buffer1);
            cout << "Gender:" << endl;
            cout << buffer1 << endl;
            cout << "Enter new gender: ";
            cin.getline(buffer, SIZE_N);
            setGender(buffer);
            break;
        case 4:
            int hours;
            cout << "Hours per day:" << endl;
            cout << getHoursPerDay() << endl;
            cout << "Enter new hours per day: ";
            cin >> hours;
            cin.ignore();
            setHoursPerDay(hours);
            break;
        case 5:
            getSubject(buffer1);
            cout << "Subject:" << endl;
            cout << buffer1 << endl;
            cout << "Enter new subject: ";
            cin.getline(buffer, SIZE_N);
            setSubject(buffer);
            break;
        case 6:
            int idx;
            cout << "Enter student index (1 to " << getStudentCount() << "): ";
            cin >> idx;
            cin.ignore();
            if (idx >= 1 && idx <= getStudentCount())
            {
                getStudent((idx - 1), buffer1);
                cout << "Student#" << idx << ":" << endl;
                cout << buffer1 << endl;
                cout << "Enter new name for student #" << idx << ": ";
                cin.getline(buffer, SIZE_N);
                setStudent(idx - 1, buffer);
            }
            else {
                cout << "Invalid index\n";
            }
            break;
        }
    } while (choice != 0);
}


bool SpecialtyTeacher::operator==(const SpecialtyTeacher& other) const
{
    char buffer1[SIZE_N], buffer2[SIZE_N];

    this->getFirstName(buffer1);
    other.getFirstName(buffer2);
    if (strcmp(other.firstName, "") != 0 && strcmp(other.firstName, "-1") != 0)
    {
        if (strcmp(buffer1, buffer2) != 0)
        {
            return false;
        }
    }

    this->getLastName(buffer1);
    other.getLastName(buffer2);
    if (strcmp(other.lastName, "") != 0 && strcmp(other.lastName, "-1") != 0)
    {
        if (strcmp(buffer1, buffer2) != 0)
        {
            return false;
        }
    }

    this->getGender(buffer1);
    other.getGender(buffer2);
    if (strcmp(other.gender, "") != 0 && strcmp(other.gender, "-1") != 0)
    {
        if (strcmp(buffer1, buffer2) != 0)
        {
            return false;
        }
    }

    if (other.getHoursPerDay() != -1 && other.getHoursPerDay() != 0)
    {
        if (this->getHoursPerDay() != other.getHoursPerDay())
        {
            return false;
        }
    }

    if (strcmp(other.subject, "") != 0 && strcmp(other.subject, "-1") != 0)
    {
        if (strcmp(this->subject, other.subject) != 0)
        {
            return false;
        }
    }

    if (other.studentCount != 0 && other.studentCount != -1)
    {
        if (this->studentCount != other.studentCount)
        {
            return false;
        }
    }

    for (int i = 0; i < other.studentCount && i < this->studentCount; ++i)
    {
        if (strcmp(other.students[i], "") != 0 && strcmp(other.students[i], "-1") != 0)
        {
            if (strcmp(this->students[i], other.students[i]) != 0)
            {
                return false;
            }
        }
    }

    return true;
}
bool SpecialtyTeacher::compareByFirstName(const SpecialtyTeacher& a, const SpecialtyTeacher& b)
{
    char name1[SIZE_N], name2[SIZE_N];
    a.getFirstName(name1);
    b.getFirstName(name2);
    return strcmp(name1, name2) < 0;
}

bool SpecialtyTeacher::compareByLastName(const SpecialtyTeacher& a, const SpecialtyTeacher& b)
{
    char last1[SIZE_N], last2[SIZE_N];
    a.getLastName(last1);
    b.getLastName(last2);
    return strcmp(last1, last2) < 0;
}

bool SpecialtyTeacher::compareByGradeOrHours(const SpecialtyTeacher& a, const SpecialtyTeacher& b)
{
    return a.getHoursPerDay() < b.getHoursPerDay();
}

bool SpecialtyTeacher::compareBySubject(const SpecialtyTeacher& a, const SpecialtyTeacher& b)
{
    char subj1[SIZE_N], subj2[SIZE_N];
    a.getSubject(subj1);
    b.getSubject(subj2);
    return strcmp(subj1, subj2) < 0;
}

bool SpecialtyTeacher::compareByStudentCount(const SpecialtyTeacher& a, const SpecialtyTeacher& b)
{
    return a.getStudentCount() < b.getStudentCount();
}

auto SpecialtyTeacher::getComparator() -> bool (*)(const SpecialtyTeacher&, const SpecialtyTeacher&) {
    int choice;
    cout << "\nSort by:\n";
    cout << "1. First name\n";
    cout << "2. Last name\n";
    cout << "3. Gender\n";
    cout << "4. Hours per day\n";
    cout << "5. Subject\n";
    cout << "6. Number of students\n";
    cout << "Choice: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
    case 1: return compareByFirstName;
    case 2: return compareByLastName;
    case 4: return compareByGradeOrHours;
    case 5: return compareBySubject;
    case 6: return compareByStudentCount;
    default: return compareByFirstName;
    }
}