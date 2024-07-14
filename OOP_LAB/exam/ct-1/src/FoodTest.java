import java.util.*;

class Pizza {
    double radius;
    double price;

    Pizza(double radius, double pppi) {
        this.radius = radius;
        this.price = this.radius * pppi;
    }

    Pizza() {
    }

    void comparePizza(Scanner sc) {
        double[] r = new double[2];
        int[] unit = new int[2];
        double[] totalArea = new double[2];

        for (int i = 0; i < 2; i++) {
            r[i] = sc.nextDouble();
            unit[i] = sc.nextInt();

            totalArea[i] = (3.14 * r[i] * r[i]) * unit[i];
        }

        if (totalArea[0] > totalArea[1])
            System.out.println("Take pizza 1");
        else
            System.out.println("Take pizza 2");
    }

    double getCost() {
        return price;
    }
}

public class FoodTest {
    public static void main(String[] args) {
        System.out.println("Please enter a choice: ");
        System.out.println("1. Price of pizza.");
        System.out.println("2. Compare areas of pizza.");

        Scanner sc = new Scanner(System.in);
        int input = sc.nextInt();

        switch (input) {
            case 1 -> {
                System.out.print("Enter radius and price per inch of pizza: ");

                double radius = sc.nextDouble();
                double pppi = sc.nextDouble();

                Pizza p = new Pizza(radius, pppi);

                System.out.println(p.getCost());
            }
            case 2 -> {
                Pizza p = new Pizza();

                p.comparePizza(sc);
            }
            default -> {
            }
        }

        sc.close();
    }
}
