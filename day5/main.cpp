#include <iostream>
using namespace std;

void setColor(int color) {
    switch (color) {
        case 1: std::cout << "\033[32m"; break;  // Green
        default: std::cout << "\033[37m"; break;  // White
    }
}

class Person { // Base class
protected:
    string name;
    int age;

public:
    Person(string name, int age){
        this->name=name;
        this->age=age;
    }

    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age;
    }

    ~Person() {
        setColor(1);
        cout << "Person Destructor for: " << name << "." << endl;
        setColor(0);
    }
};

class Student : public Person { // one level inheritance
protected:
    string collageName;

public:
    Student(string name, int age, string collageName): Person(name, age){
        this->collageName=collageName;
    }

    void displayInfo(){ // method overriding
        Person::displayInfo();
        cout << ", Collage Name: " << collageName << endl;
    }

    ~Student() {
        setColor(1);
        cout << "Student Destructor for: " << name << "." << endl;
        setColor(0);
    }
};

class Employee : public Person { // one level inheritance
protected:
    string jobTitle;

public:
    Employee(string name, int age, string jobTitle) : Person(name, age) {
        this->jobTitle = jobTitle;
    }

    void displayInfo(){ // method overriding
        Person::displayInfo();
        cout << ", JobTitle: " << jobTitle << endl;
    }

    ~Employee() {
        setColor(1);
        cout << "Employee Destructor for: " << name << "." << endl;
        setColor(0);
    }
};

class Admin : public Employee { // two level inheritance
protected:
    string department;

public:
    Admin(string name, int age, string jobTitle, string department) : Employee(name, age, jobTitle) {
        this->department = department;
    }

    void displayInfo(){ // method overriding
        Employee::displayInfo();
        cout << ", Department: " << department << endl;
    }

    ~Admin() {
        setColor(1);
        cout << "Admin Destructor for: " << name << "." << endl;
        setColor(0);
    }
};

class Engineer : public Employee { // two level inheritance
protected:
    string specialization;
    string type;
    double salary;

public:
    Engineer(string name, int age, string jobTitle, string specialization, string type, double salary) : Employee(name, age, jobTitle) {
        this->specialization = specialization;
        this->salary = salary;
        this->type = type;
    }


    double calculateTaxes() {
        return salary * 0.14;
    }
    double calculateTaxes(double percentage) { // method overloading
        return salary * percentage;
    }

     void displayInfo(){ // method overriding
        Employee::displayInfo();
        cout << ", Specialization: " << specialization << ", Type: " << type  << ", Salary: $" << salary << endl;
    }

    ~Engineer() {
        setColor(1);
        cout << "Engineer Destructor for: " << name << "." << endl;
        setColor(0);
    }
};

int main() {
    Person person("A7med", 40);
    Student student("Ali", 20, "Ain shams");
    Employee employee("Mohamed", 30, "Manager");
    Admin admin("zaki", 35, "Admin Manager", "HR");
    Engineer engineer("Messi", 28, "Software Engineer", "Backend Development", "full time", 20000);  

    // Overriding example
    setColor(1);
    cout << "*Overriding Example:" << endl;
    setColor(0);
    cout << "1) Person Info:- ";
    person.displayInfo();
    cout << endl;
    cout << "2) Student Info:- ";
    student.displayInfo();
    cout << "3) Employee Info:- ";
    employee.displayInfo();
    cout << "4) Admin Info:- ";
    admin.displayInfo();
    cout << "5) Engineer Info:- ";
    engineer.displayInfo();
    cout << endl;

    // Overloading example
    setColor(1);
    cout << "*Overloading Example:" << endl;
    setColor(0);
    double tax = engineer.calculateTaxes();
    cout << "Tax1: $" << tax << endl;
    tax = engineer.calculateTaxes(0.2);
    cout << "Tax2: $" << tax << endl;
    cout << endl;

    // Upcasting example
    setColor(1);
    cout << "*Upcasting Example:" << endl;
    setColor(0);
    Engineer engineerData("ZIKOOOO", 23, "Software Engineer", "Backend(laravel)", "fulltime", 20000);
    Person* personPtr = &engineerData;
    cout << "ex1: ";
    personPtr->Person::displayInfo();
    cout << "\nex2: ";
    personPtr->displayInfo();
    cout << "\n\n\n";
    return 0;
}
