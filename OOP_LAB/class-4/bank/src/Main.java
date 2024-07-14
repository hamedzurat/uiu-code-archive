abstract class BankAcc {
    String Type;
    int id;
    String name;
    private double balance = 0;

    BankAcc(int id, double balance, String name) {
        this.id = id;
        this.balance = balance;
        this.name = name;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            System.out.println("withdraw amount is larger than balance");
            return;
        }
        balance -= amount;
    }

    void check() {
        System.out.println("Type: " + Type + "\nName: " + name + "\nBalance: " + balance);
    }

    public double getBalance() {
        return balance;
    }
}

class Savigs_acc extends BankAcc {
    double interest;

    {
        super.Type = "savings";
    }

    Savigs_acc(int id, double balance, String name, double interest) {
        super(id, balance, name);
        this.interest = interest;
    }

    @Override
    void deposit(double amount) {
        System.out.println("adding interest: " + (amount * interest));
        amount += (amount * interest);
        super.deposit(amount);
    }

    @Override
    void check() {
        System.out.println("Name: " + name + "\nBalance: " + getBalance() + "\nInterest: " + interest);
    }

}

class Current_acc extends BankAcc {
    double withdraw_charge;

    {
        super.Type = "current";
    }

    Current_acc(int id, double balance, String name, double withdraw_charge) {
        super(id, balance, name);
        this.withdraw_charge = withdraw_charge;
    }

    @Override
    void withdraw(double amount) {
        super.withdraw(amount + withdraw_charge);
    }

    @Override
    void check() {
        System.out.println("Name: " + name + "\nBalance: " + getBalance() + "\nwithdraw_charge: " + withdraw_charge);
    }

}

class Student_acc extends BankAcc {
    {
        super.Type = "student";
    }

    Student_acc(int id, double balance, String name) {
        super(id, balance, name);
    }

}

public class Main {
    public static void main(String[] args) {

        BankAcc u1 = new Current_acc(01, 3000, "user1", 99);

        u1.check();
        u1.deposit(333);
        u1.check();
        u1.withdraw(1111);
        u1.check();
        u1.withdraw(5555);
        u1.check();

        System.out.print("\n\n\n\n");

        BankAcc u2 = new Savigs_acc(02, 3000, "user2", .1);

        u2.check();
        u2.deposit(333);
        u2.check();
        u2.withdraw(1111);
        u2.check();
        u2.withdraw(5555);
        u2.check();

        System.out.print("\n\n\n\n");

        BankAcc u3 = new Student_acc(02, 3000, "user3");

        u3.check();
        u3.deposit(333);
        u3.check();
        u3.withdraw(1111);
        u3.check();
        u3.withdraw(5555);
        u3.check();

    }
}
