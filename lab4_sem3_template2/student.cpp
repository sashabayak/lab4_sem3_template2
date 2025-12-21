#include "Student.h"

Student::Student()
{
    grade = 0;
}


bool Student::compareByFirstName(const Student& a, const Student& b)
{
    char name1[SIZE_N], name2[SIZE_N];
    a.getFirstName(name1);
    b.getFirstName(name2);
    return strcmp(name1, name2) < 0;
}

bool Student::compareByLastName(const Student& a, const Student& b)
{
    char last1[SIZE_N], last2[SIZE_N];
    a.getLastName(last1);
    b.getLastName(last2);
    return strcmp(last1, last2) < 0;
}

bool Student::compareByGradeOrHours(const Student& a, const Student& b)
{
    return a.grade < b.grade;
}

istream& operator>>(std::istream& in, Student& s)
{
    in >> static_cast<Person&>(s);                                    // ????? ????????? ????? ??? ???????? ?????? Person, ????????? ?????????? ???? Student& ? Person&. 
    cout << "Enter grade: ";
    cin >> s.grade;
    return in;
}

ostream& operator<<(std::ostream& out, const Student& s)
{
    out << static_cast<const Person&>(s)
        << setw(15) << s.grade;
    return out;
}

void Student::printHeader() const
{
    cout << setw(15) << "First Name"
        << setw(15) << "Last Name"
        << setw(10) << "Gender"
        << setw(15) << "Grade" << endl;
}


int Student::getGrade() const
{
    return grade;
}

void Student::setGrade(int val)
{
    grade = val;
}

Student& Student::operator=(const Student& other)
{
    if (this != &other)
    {
        Person::operator=(other);
        grade = other.grade;
    }
    return *this;
}

void Student::editStudent()
{
    char buffer[SIZE_N];
    char buffer1[SIZE_N];
    int choice;
    do {
        cout << "\nChoose field to edit:\n";
        cout << "1. First Name\n2. Last Name\n3. Gender\n4. Grade\n5. Specialty\n0. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
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
            getGrade();
            cout << "Grade:" << endl;
            cout << buffer1 << endl;
            cout << "Enter new grade: ";
            int val;
            cin >> val;
            setGrade(val);
            break;
        }
    } while (choice != 0);
}

bool Student::operator==(const Student& other) const {

    if (strcmp(other.firstName, "") != 0 && strcmp(other.firstName, "-1") != 0)
    {
        if (strcmp(this->firstName, other.firstName) != 0)
        {
            return false;
        }
    }

    if (strcmp(other.lastName, "") != 0 && strcmp(other.lastName, "-1") != 0)
    {
        if (strcmp(this->lastName, other.lastName) != 0)
        {
            return false;
        }
    }

    if (strcmp(other.gender, "") != 0 && strcmp(other.gender, "-1") != 0)
    {
        if (strcmp(this->gender, other.gender) != 0)
        {
            return false;
        }
    }


    if (other.grade != 0 && other.grade != -1)
    {
        if (this->grade != other.grade)
        {
            return false;
        }
    }

    return true;
}

auto Student::getComparator() -> bool (*)(const Student&, const Student&) {
    int choice;
    cout << "\nSort by:\n";
    cout << "1. First name\n";
    cout << "2. Last name\n";
    cout << "4. Grade\n";
    cout << "Choice: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
    case 1: return compareByFirstName;
    case 2: return compareByLastName;
    case 4: return compareByGradeOrHours;
    default: return compareByFirstName; // fallback
    }
}