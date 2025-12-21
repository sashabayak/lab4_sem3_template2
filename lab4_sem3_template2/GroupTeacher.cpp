#include "GroupTeacher.h"

GroupTeacher::GroupTeacher() : studentCount(0)
{
    subject[0] = '\0';
    for (int i = 0; i < MAX_GROUPS; i++)
    {
        students[i][0] = '\0';
    }
}

istream& operator>>(istream& in, GroupTeacher& gt)
{
    in >> static_cast<Teacher&>(gt);
    cout << "Enter subject (e.g. Choir, Solfeggio): ";
    in.getline(gt.subject, SIZE_N);
    cout << "Enter number of groups (max " << MAX_GROUPS << "): ";
    in >> gt.studentCount;
    if (gt.studentCount > MAX_GROUPS)
    {
        gt.studentCount = MAX_GROUPS;
    }
    in.ignore();
    for (int i = 0; i < gt.studentCount; i++)
    {
        cout << "Enter name of group #" << (i + 1) << ": ";
        in.getline(gt.students[i], SIZE_N);
    }
    return in;
}

ostream& operator<<(ostream& out, const GroupTeacher& gt)
{
    out << static_cast <const Teacher&>(gt);
    out << setw(20) << gt.subject;
    out << setw(30);
    for (int i = 0; i < gt.studentCount; i++)
    {
        out << gt.students[i];
        if (i != gt.studentCount - 1)
        {
            out << "," << endl << setw(105);
        }
    }
    cout << ".";
    return out;
}

void GroupTeacher::printHeader() const
{
    cout << setw(15) << "First Name"
        << setw(15) << "Last Name"
        << setw(10) << "Gender"
        << setw(15) << "Hours/Day"
        << setw(20) << "Subject"
        << setw(30) << "Students" << endl;
}

void GroupTeacher::getSubject(char* buffer) const
{
    strcpy_s(buffer, SIZE_N, subject);
}

void GroupTeacher::setSubject(const char* val)
{
    strncpy_s(subject, SIZE_N, val, _TRUNCATE);
}

int GroupTeacher::getStudentCount() const
{
    return studentCount;
}

void GroupTeacher::setStudentCount(int val)
{
    if (val <= MAX_GROUPS)
    {
        studentCount = val;
    }
}
void GroupTeacher::getStudent(int index, char* buffer) const
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

void GroupTeacher::setStudent(int index, const char* val)
{
    if (index >= 0 && index < studentCount)
    {
        strncpy_s(students[index], SIZE_N, val, _TRUNCATE);
    }
}

GroupTeacher& GroupTeacher::operator=(const GroupTeacher& other)
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

void GroupTeacher::editGroupTeacher()
{
    char buffer[SIZE_N];
    char buffer1[SIZE_N];
    int choice;
    do {
        cout << "\nChoose field to edit:\n";
        cout << "1. First Name\n2. Last Name\n3. Gender\n4.Hours/Day\n5. Department\n6. Groups\n0. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1:
            getFirstName(buffer1);
            cout << "First Name:" << endl;
            cout << buffer1 << endl;
            cout << "Enter new first name: ";
            cin.getline(buffer, SIZE_N);
            setFirstName(buffer);
            break;
        case 2:
            getLastName(buffer1);
            cout << "Last Name:" << endl;
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
            cout << "Enter new Hours\Day: ";
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
            if (idx >= 1 && idx <= getStudentCount()) {
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

bool GroupTeacher::compareByFirstName(const GroupTeacher& a, const GroupTeacher& b) {
    char name1[SIZE_N], name2[SIZE_N];
    a.getFirstName(name1);
    b.getFirstName(name2);
    return strcmp(name1, name2) < 0;
}

bool GroupTeacher::compareByLastName(const GroupTeacher& a, const GroupTeacher& b) {
    char last1[SIZE_N], last2[SIZE_N];
    a.getLastName(last1);
    b.getLastName(last2);
    return strcmp(last1, last2) < 0;
}

bool GroupTeacher::compareByGradeOrHours(const GroupTeacher& a, const GroupTeacher& b) {
    return a.getHoursPerDay() < b.getHoursPerDay();
}

bool GroupTeacher::compareBySubject(const GroupTeacher& a, const GroupTeacher& b) {
    char dept1[SIZE_N], dept2[SIZE_N];
    a.getSubject(dept1);
    b.getSubject(dept2);
    return strcmp(dept1, dept2) < 0;
}

bool GroupTeacher::compareByStudentCount(const GroupTeacher& a, const GroupTeacher& b) {
    return a.getStudentCount() < b.getStudentCount();
}


bool GroupTeacher::operator==(const GroupTeacher& other) const {
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

    if (other.getHoursPerDay() != -1 && other.getHoursPerDay() != 0) {
        if (this->getHoursPerDay() != other.getHoursPerDay()) return false;
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

auto GroupTeacher::getComparator() -> bool (*)(const GroupTeacher&, const GroupTeacher&) {
    int choice;
    cout << "\nSort by:\n";
    cout << "1. First name\n";
    cout << "2. Last name\n";
    cout << "4. Hours per day\n";
    cout << "5. Subject\n";
    cout << "6. Number of groups\n";
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