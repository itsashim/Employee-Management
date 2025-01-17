## Documentation for Employee Management System

## Overview
The EMS program is a console-based application that allows users to:
  1)Add new employees.
  2)Display all employees.
  3)Delete an employee by ID.
  4)Exit the application.
  
## Code Structure
1. Struct: Employee
   The Employee struct is used to represent an individual employee. It contains the following fields:

      id: An integer representing the unique ID of the employee.
      name: A string for the employee's name.
      position: A string for the employee's job position.
      salary: A double representing the employee's salary.

   
3. Class: EmployeeManagementSystem
    This class contains all the functionalities of the program.

      ### Private Members
      # employees: A vector of Employee objects to store the employee records.
      findEmployeeById(int id): A helper function to search for an employee by their ID. Returns the index of the employee or -1 if not found.
      Public Methods
      # addEmployee(): Prompts the user to input employee details and adds the employee to the system after validation.
      # displayEmployees(): Displays all employees in a formatted list. Shows a message if no employees are present.
      # deleteEmployee(): Deletes an employee based on their ID. Notifies the user if the ID is invalid or not found.
      # menu(): Displays the main menu and handles user choices to execute various operations.

   
3. Main Function
    The main() function creates an instance of the EmployeeManagementSystem class and starts the program by calling the menu() method.

# How to Use
Compile and Run: Use a C++ compiler to compile and execute the program. For example:

Menu Options:
  1: Add Employee
    Enter the employee's ID, name, position, and salary. The program validates inputs and ensures the ID is unique.
  2: Display Employees
    Shows a list of all employees in a formatted table.
  3: Delete Employee
    Enter the ID of the employee to be deleted. If the ID is not found, an error message is displayed.
  4: Exit
    Exits the program.


# Key Features

Error Handling:
  Prevents duplicate IDs.
  Ensures valid input types for IDs and salaries.
  Handles empty input for names and positions.
  
User-Friendly Output:
  Clearly formatted employee list.
  Descriptive error and success messages.
  
Scalability:
  Uses a dynamic vector for managing employees, allowing easy addition and deletion.
  Sample Input/Output
  
### Menu Display

--- Employee Management System ---
1. Add Employee
2. Display Employees
3. Delete Employee
4. Exit
Enter your choice:


## Adding an Employee

  Enter Employee ID (positive integer): 101
  Enter Employee Name: John Doe
  Enter Employee Position: Manager
  Enter Employee Salary (positive number): 50000
  Employee added successfully!


## Displaying Employees
--- Employee List ---
--------------------------------------------
ID      Name            Position        Salary
--------------------------------------------
101     John Doe        Manager         50000
--------------------------------------------


## Deleting an Employee

  Enter Employee ID to delete: 101
  Employee deleted successfully!
  
