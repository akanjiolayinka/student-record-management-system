#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    int id;
    string name;
    int age;
    string grade;
};

vector<Student> students;


void addStudents() {
    Student s;

    cout << "Enter STUDENT ID: \n";
    cin >> s.id;

    cout << "Enter your Name: \n";
    cin >> s.name;

    cout << "Enter your Age: \n";
    cin >> s.age;

    cout << "Enter your Grade: \n";
    cin >> s.grade;

    students.push_back(s);

    cout << "****Student added Succesfully****\n";

}
void displayStudents() {
    if (students.empty()) {
        cout << "No students Available!\n";
        return;
    }

    cout << "\n********************Student List*******************\n";

    for (int i = 0; i < students.size(); i++) {
        cout << "ID: " << students[i].id << endl;

        cout << "Name: " << students[i].name << endl;

        cout << "Age: " << students[i].age << endl;

        cout  << "Grade: " << students[i].grade << endl;

        cout << "**************************************************\n";
    }
}

void searchStudents() {
    int searchID;
    bool found = false;

    cout << "Enter Student ID to search: ";
    cin >> searchID;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == searchID) {
            cout << "\nStudent Found:\n";
            cout << "ID: " << students[i].id << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "Grade: " << students[i].grade << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student not found.\n";
    }
}
void deleteStudents() {
    int deleteID;
    bool found = false;

    cout << "Enter Student's Id to delete: ";

    cin >> deleteID;

    for (int i = 0; i < students.size(); i++) {
        if(students[i].id == deleteID) {
            students.erase(students.begin() + i);

            cout << "Students deleted successfully: \n";
            found = true;
            break;
        }
    }
    if(!found) {
        cout << "********Student not found*******\n";
    }
}
int main() {
    int choice = 0;
    do {
        cout << "STUDENT Management System\n";
        cout << "1. Add students\n";
        cout << "2. View all STUDENT\n";
        cout << "3. Search student by ID\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice: ";

        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                addStudents();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudents();
                break;
            case 4:
                deleteStudents();
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please enter 1–5.\n";
        }
    } while (choice != 5);
    return 0;
}
