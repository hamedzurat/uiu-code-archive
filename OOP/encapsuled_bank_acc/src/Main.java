class BankAccount {
    private int account_number;
    private String account_holder_name;
    private int balance;

    BankAccount(int account_number, String account_holder_name, int balance){
        this.account_number=account_number;
        this.account_holder_name=account_holder_name;
        this.balance=balance;
    }

    void deposit(int amount){
        balance+=amount;
    }

    void withdraw(int amount){
        if(amount>balance){
            System.out.println("ERROR: YOU ARE TOO POOR (:");
            return;
        }
        balance-=amount;
    }

    int check_balance(){
        return balance;
    }

}

public class Main {
    public static void main(String[] args) {
        BankAccount u = new BankAccount(123456,"John Doe",1000);

        u.deposit(500);
        u.withdraw(200);
        System.out.println(u.check_balance());
    }
}
