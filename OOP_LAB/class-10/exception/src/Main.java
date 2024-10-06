class MyException extends Exception {
    MyException(String msg) {
        super(msg);
    }
}


class Product {
    void productCheck(int weight) throws MyException {
        if (weight < 100) throw new MyException("product is invalid");
        System.out.println(weight);
    }
}


class Calculator {
    private final int a, b;

    Calculator(int a, int b) {
        this.a = a;
        this.b = b;
    }

    int add() throws ArithmeticException {
        if (a < 0 || b < 0) throw new ArithmeticException("Negative number not allowed");

        return a + b;
    }

    int sub() throws ArithmeticException {
        if (a < 0 || b < 0) throw new ArithmeticException("Negative number not allowed");

        return a - b;
    }

    int mult() {
        if (a == 0 || b == 0) throw new ArithmeticException("zero is not allowed");

        return a * b;
    }

    double div() {
        if (a == 0 || b == 0) throw new ArithmeticException("zero is not allowed");

        return (double) a / b;
    }
}


public class Main {
    public static void main(String[] args) {
        try {
            new Product().productCheck(1);
        } catch (MyException e) {
            System.out.println("ERROR: " + e.getMessage());
        }

//
//
//

        int a = '6';
        int b = '8';

        try {
            if (!Character.isDigit(a) || !Character.isDigit(b))
                throw new NumberFormatException("ERROR: 418 I'm a calculator");
        } catch (NumberFormatException e) {
            System.out.println("Syntax ERROR: " + e.getMessage());
        }

        System.out.println(new Calculator(3, 4).add());
        System.out.println(new Calculator(3, 4).sub());
        System.out.println(new Calculator(3, 4).mult());
        System.out.println(new Calculator(3, 4).div());

        try {
            System.out.println(new Calculator(-3, 4).add());
        } catch (ArithmeticException e) {
            System.out.println("Math ERROR: " + e.getMessage());
        }

        try {
            System.out.println(new Calculator(3, -4).sub());
        } catch (ArithmeticException e) {
            System.out.println("Math ERROR: " + e.getMessage());
        }

        try {
            System.out.println(new Calculator(0, 4).mult());
        } catch (ArithmeticException e) {
            System.out.println("Math ERROR: " + e.getMessage());
        }

        try {
            System.out.println(new Calculator(3, 0).div());
        } catch (ArithmeticException e) {
            System.out.println("Math ERROR: " + e.getMessage());
        }
    }
}
