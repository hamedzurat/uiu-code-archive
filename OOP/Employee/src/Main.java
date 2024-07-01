class Employee {
    String name;
    int salary;

    Employee(String name, int salary) {
        this.name = name;
        this.salary = salary;
    }

    int getSalary() {
        return salary;
    }

    int getAnnualSalary() {
        return salary * 12;
    }

    void raiseSalary(int var) {
        salary += var;
    }
}

public class Main {
    public static void main(String[] args) {

        Employee e = new Employee("username", 30_000);

        System.out.println("monthly salary: " + e.getSalary());
        System.out.println("annually salary: " + e.getAnnualSalary());

        e.raiseSalary(5_555);

        System.out.println("monthly salary: " + e.getSalary());
        System.out.println("annually salary: " + e.getAnnualSalary());
    }
}
