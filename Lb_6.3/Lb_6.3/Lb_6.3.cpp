#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(const string& _name, int _age) : name(_name), age(_age) {}
    virtual ~Person() {}

    virtual void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    friend istream& operator>>(istream& in, Person& person) {
        in >> person.name;
        in >> person.age;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Person& person) {
        out << "Name: " << person.name << ", Age: " << person.age;
        return out;
    }
};

class Employee : public Person {
protected:
    string position;
    double salary;

public:
    Employee(const string& _name, int _age, const string& _position, double _salary)
        : Person(_name, _age), position(_position), salary(_salary) {}

    void display() const override {
        Person::display();
        cout << "Position: " << position << ", Salary: " << salary << endl;
    }

    friend istream& operator>>(istream& in, Employee& employee) {
        in >> employee.name;
        in >> employee.age;
        in >> employee.position;
        in >> employee.salary;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Employee& employee) {
        out << static_cast<const Person&>(employee) << ", Position: " << employee.position << ", Salary: " << employee.salary;
        return out;
    }
};

class Family {
protected:
    string familyRole;

public:
    Family(const string& _role) : familyRole(_role) {}
    virtual ~Family() {}

    virtual void display() const {
        cout << "Family Role: " << familyRole << endl;
    }

    friend istream& operator>>(istream& in, Family& family) {
        in >> family.familyRole;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Family& family) {
        out << "Family Role: " << family.familyRole;
        return out;
    }
};

class EmployeeFamily : public Employee, public Family, public Person {
public:
    EmployeeFamily(const string& _name, int _age, const string& _position, double _salary, const string& _role)
        : Person(_name, _age), Employee(_name, _age, _position, _salary), Family(_role) {}

    void display() const override {
        Employee::display();
        Family::display();
    }
};

int main() {
    EmployeeFamily empFam("John Doe", 35, "Manager", 5000, "Father");
    empFam.display();
    return 0;
}
