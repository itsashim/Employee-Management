#include <iostream>
#include <vector>
#include <string>
#include <limits> 

using namespace std;

struct Employee {
    int id;
    string name;
    string position;
    double salary;
};

class EmployeeManagementSystem {
private:
    vector<Employee> employees;

    int findEmployeeById(int id) {
        for (size_t i = 0; i < employees.size(); ++i) {
            if (employees[i].id == id) {
                return i;
            }
        }
        return -1;
    }

    void clearInput() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

public:
    void addEmployee() {
        Employee emp;

        cout << "Enter Employee ID (positive integer): ";
        while (!(cin >> emp.id) || emp.id <= 0) {
            cout << "Invalid input. Please enter a positive integer for ID: ";
            clearInput();
        }
        clearInput();

        if (findEmployeeById(emp.id) != -1) {
            cout << "Error: Employee with ID " << emp.id << " already exists!\n";
            return;
        }

        cout << "Enter Employee Name: ";
        getline(cin, emp.name);
        if (emp.name.empty()) {
            cout << "Error: Name cannot be empty.\n";
            return;
        }

        cout << "Enter Employee Position: ";
        getline(cin, emp.position);
        if (emp.position.empty()) {
            cout << "Error: Position cannot be empty.\n";
            return;
        }

        cout << "Enter Employee Salary (positive number): ";
        while (!(cin >> emp.salary) || emp.salary <= 0) {
            cout << "Invalid input. Please enter a positive number for salary: ";
            clearInput();
        }
        clearInput();

        employees.push_back(emp);
        cout << "Employee added successfully!\n";
    }

    void displayEmployees() {
        if (employees.empty()) {
            cout << "No employees to display.\n";
            return;
        }

        cout << "\n--- Employee List ---\n";
        cout << "--------------------------------------------\n";
        cout << "ID\tName\t\tPosition\tSalary\n";
        cout << "--------------------------------------------\n";
        for (const auto& emp : employees) {
            cout << emp.id << "\t" << emp.name << "\t\t" << emp.position << "\t" << emp.salary << "\n";
        }
        cout << "--------------------------------------------\n";
    }

    void deleteEmployee() {
        int id;
        cout << "Enter Employee ID to delete: ";
        while (!(cin >> id) || id <= 0) {
            cout << "Invalid input. Please enter a valid positive integer for ID: ";
            clearInput();
        }
        clearInput();

        int index = findEmployeeById(id);
        if (index == -1) {
            cout << "Error: Employee with ID " << id << " not found!\n";
            return;
        }

        employees.erase(employees.begin() + index);
        cout << "Employee deleted successfully!\n";
    }

    void menu() {
        while (true) {
            cout << "\n--- Employee Management System ---\n";
            cout << "1. Add Employee\n";
            cout << "2. Display Employees\n";
            cout << "3. Delete Employee\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            
            int choice;
            if (!(cin >> choice)) {
                cout << "Invalid input. Please enter a number between 1 and 4.\n";
                clearInput();
                continue;
            }

            clearInput();
            switch (choice) {
                case 1:
                    addEmployee();
                    break;
                case 2:
                    displayEmployees();
                    break;
                case 3:
                    deleteEmployee();
                    break;
                case 4:
                    cout << "Exiting program. Goodbye!\n";
                    return;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }
    }
};

int main() {
    EmployeeManagementSystem ems;
    ems.menu();
    return 0;
}
