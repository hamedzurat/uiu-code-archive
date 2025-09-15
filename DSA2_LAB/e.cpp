#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee {
    string name;
    double salary;

    void setSalary(double s) {
        salary = s;
    }

    public:
    int id;
    double getSalary() {
        return salary;
    }

    Employee(string n, int i, double s)
    : id(i), name(n), salary(s) {};
    string display() {
        return "ID: " + to_string(id) + " Name: " + name + " Salary: " + to_string(salary);
    }

    bool isMoreThan10k() {
        if(salary >= 10000) return true;
        return false;
    }

    bool isMoreThan15k() {
        if(salary >= 15000) return true;
        return false;
    }

    void Increment(double percentage) {
        salary += salary * percentage / 100;
    }
};
bool compareId(Employee e1, Employee e2) {
    return e1.id < e2.id;
}
bool compareSalary(Employee e1, Employee e2) {
    return e1.getSalary() < e2.getSalary();
}

int main() {
    vector<Employee> e = {
        Employee("Rahim", 2, 8000),
        Employee("Karim", 1, 15000),
        Employee("Abir", 3, 9000),
        Employee("Roni", 4, 18000)
    };

    for(auto& x : e) {
        if(x.isMoreThan10k()) cout << x.display() << endl;
        if(x.isMoreThan15k())
            x.Increment(15);
        else
            x.Increment(10);
    }

    sort(e.begin(), e.end(), compareId);
    sort(e.rbegin(), e.rend(), compareSalary);

    cout << endl
         << "--------------------------------------------" << endl;
    for(auto x : e) cout << x.display() << endl;

    return 0;
}
