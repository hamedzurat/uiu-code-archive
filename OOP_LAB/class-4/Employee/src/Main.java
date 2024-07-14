import java.util.*;

class Employee {
    private final int id;
    private final String type;
    String name;

    Employee(String type, String name) {
        id = (int) (Math.random() * 10000);
        this.type = type;
        this.name = name;
    }

    void about(String whatever) {
        System.out.println("id: " + id + "\tType: " + type + "\t\tName:" + name + "\t" + whatever);
    }

    boolean isType(String S) {
        return (type == S);
    }

}

class Salaried_employee extends Employee {

    int salary;

    Salaried_employee(String name, int salary) {
        super("Salaried", name);
        this.salary = salary;
    }

    Salaried_employee(String type, String name, int salary) {
        super(type, name);
        this.salary = salary;
    }

    @Override
    void about(String whatever) {
        super.about(" Salary: " + salary + "\t" + whatever);
    }

}

class Hourly_employee extends Employee {
    int hourly;

    Hourly_employee(String name, int hourly) {
        super("Hourly", name);
        this.hourly = hourly;
    }

    @Override
    void about(String whatever) {
        super.about(" Hourly: " + hourly + "\t" + whatever);
    }
}

class Commissioned_employee extends Employee {
    int commission;

    Commissioned_employee(String name, int commission) {
        super("Commissioned", name);
        this.commission = commission;
    }

    @Override
    void about(String whatever) {
        super.about(" Commission: " + commission + "\t" + whatever);
    }
}

class Salaried_and_Commissioned_employee extends Salaried_employee {
    int commission;

    Salaried_and_Commissioned_employee(String name, int salary, int commission) {
        super("Salaried_and_Commissioned", name, salary);
        this.commission = commission;
    }

    @Override
    void about(String whatever) {
        super.about(" Commission: " + commission + "\t" + whatever);
    }
}


class Employee_record_system {
    String name;
    ArrayList<Employee> A = new ArrayList<Employee>();

    Employee_record_system(String name) {
        this.name = name;
        System.out.println("Employee record system for " + name);
    }

    void addNew(int type, String name, int... num) {
        Employee E;

        switch (type) {
            case 1 -> E = new Salaried_employee(name, num[0]);
            case 2 -> E = new Hourly_employee(name, num[0]);
            case 3 -> E = new Commissioned_employee(name, num[0]);
            case 4 -> E = new Salaried_and_Commissioned_employee(name, num[0], num[1]);
            default -> E = new Employee("", "");
        }

        A.add(E);
    }

    void printAll() {
        for (Employee E : A)
            E.about("");
    }

    void about(String name) {
        for (Employee E : A)
            if (E.name == name) E.about("");
    }

    void update(String old_name, String new_name) {
        for (Employee E : A)
            if (E.name == old_name) E.name = new_name;
    }

    void list_by_type(String S) {
        for (Employee E : A)
            if (E.isType(S)) E.about("");
    }
}


public class Main {
    public static void main(String[] args) {
        Employee_record_system uiu = new Employee_record_system("UIU");
        uiu.addNew(1, "a", 1110);
        uiu.addNew(2, "q", 2220);
        uiu.addNew(3, "w", 3330);
        uiu.addNew(4, "e", 4440, 22);
        uiu.addNew(1, "r", 5550);
        uiu.addNew(2, "t", 6660);
        uiu.addNew(3, "y", 7770);
        uiu.addNew(4, "u", 8880, 33);
        uiu.addNew(1, "i", 9990);
        uiu.addNew(2, "o", 1010);
        uiu.addNew(3, "s", 8888);
        uiu.addNew(4, "d", 9999, 44);
        uiu.addNew(5555, "asdjalsdjlkajdklalkdjalk", 0);

        uiu.printAll();

        System.out.print("\n\n\n\n");

        uiu.about("d");
        uiu.update("d", "z");
        uiu.about("z");

        System.out.print("\n\n\n\n");

        uiu.list_by_type("Salaried");
        uiu.list_by_type("Hourly");
        uiu.list_by_type("Commissioned");
        uiu.list_by_type("Salaried_and_Commissioned");
    }
}
