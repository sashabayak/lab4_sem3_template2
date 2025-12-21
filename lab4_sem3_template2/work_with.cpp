#include "work_with.h"
#include <string>

template<typename T>
void queueMenu(const string& menuTitle)
{
    Queue<T> queue;
    int choice;

    do {
        cout << "\n--- " << menuTitle << " ---\n";
        cout << "1. Add\n";
        cout << "2. Remove\n";
        cout << "3. Print Queue\n";
        cout << "4. Find\n";
        cout << "5. Sort\n";
        cout << "0. Back to Main Menu\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            T item;
            cin >> item;
            queue.enqueue(item);
            cout << "Item added to queue.\n";
            break;
        }
        case 2: {
            T removed;
            if (queue.dequeue(removed)) {
                cout << "Removed item:\n";
                removed.printHeader();
                cout << removed << endl;
            }
            else {
                cout << "Queue is empty.\n";
            }
            break;
        }
        case 3: {
            T item;
            cout << "\nItems in queue:\n";
            item.printHeader();
            queue.print();
            break;
        }
        case 4: {

            T searchItem;
            cin >> searchItem;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nSearching...\n";
            queue.find(searchItem);
        }
              break;
        case 5: {
            auto comparator = T::getComparator();
            queue.sort(comparator);
            cout << "Queue sorted by selected field.\n";
            break;
        }
        default:
            if (choice != 0) {
                cout << "Invalid choice. Please try again.\n";
            }
            break;
        }


    } while (choice != 0);
}


void mainMenu()
{
    int mainChoice;
    do
    {
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Students\n";
        cout << "2. Specialty Teachers\n";
        cout << "3. Grouop Teachers\n";
        cout << "0. Exit Program\n";
        cout << "Choice: ";
        cin >> mainChoice;
        cin.ignore();

        switch (mainChoice) {
        case 1:
            queueMenu<Student>("Student Queue Menu");
            break;
        case 2:
            queueMenu<SpecialtyTeacher>("Specialty Teacher Queue Menu");
            break;
        case 3:
            queueMenu<GroupTeacher>("Group Teacher Queue Menu");
            break;
        case 0:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (mainChoice != 0);
}