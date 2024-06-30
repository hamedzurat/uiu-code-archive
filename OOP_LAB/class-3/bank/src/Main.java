class BankAcc {
    int id;
    String name;
    private int balance = 0;

    BankAcc(int id, int balance, String name) {
        this.id = id;
        this.balance = balance;
        this.name = name;
    }

    void deposit(int amount) {
        balance += amount;
    }

    void withdraw(int amount) {
        if (amount > balance) {
            System.out.println("withdraw amount is larger than balance");
            return;
        }
        balance -= amount;
    }

    void check() {
        System.out.println("Name: " + name + "\nBalance: " + balance);
    }
}

public class Main {
    public static void main(String[] args) {

        BankAcc u1 = new BankAcc(01, 3000, "user1");

        u1.check();
        u1.deposit(333);
        u1.check();
        u1.withdraw(1111);
        u1.check();
        u1.withdraw(5555);
        u1.check();

    }
}
