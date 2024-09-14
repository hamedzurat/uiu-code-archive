abstract class Employee {
    private String name;
    private float salary;

    public Employee(String name, float salary) {
        this.name = name;
        this.salary = salary;
    }

    public String getName() {
        return this.name;
    }

    public float getSalary() {
        return this.salary;
    }

    public abstract void printSalary();
}

class SuperStarEmployee extends Employee {
    float bonusRate = 10 / 100f;
    float bonus;
    float totalSalary;

    public SuperStarEmployee(String name, float salary) {
        super(name, salary);

        bonus = super.getSalary() * bonusRate;
        totalSalary = super.getSalary() + bonus;
    }

    @Override
    public void printSalary() {
        System.out.println("Name: " + super.getName());
        System.out.println("Bonus: " + bonus);
        System.out.println("Total: " + totalSalary);
    }
}

class StarEmployee extends Employee {
    float bonusRate = 5 / 100f;
    float bonus;
    float totalSalary;

    public StarEmployee(String name, float salary) {
        super(name, salary);

        bonus = super.getSalary() * bonusRate;
        totalSalary = super.getSalary() + bonus;
    }

    @Override
    public void printSalary() {
        System.out.println("Name: " + super.getName());
        System.out.println("Bonus: " + bonus);
        System.out.println("Total: " + totalSalary);
    }
}

public class Main {
    public static void main(String[] args) {
        Employee A = new SuperStarEmployee("A", 1000);
        Employee B = new StarEmployee("B", 5000);

        A.printSalary();
        System.out.println();
        B.printSalary();
    }
}
