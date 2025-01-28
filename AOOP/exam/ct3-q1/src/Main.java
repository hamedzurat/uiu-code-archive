import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int numOfCars = sc.nextInt();
        int lotSize = sc.nextInt();

        ParkingLot lot = new ParkingLot(lotSize);
        ArrayList<Car> cars = new ArrayList<>();

        for (int i = 1; i <= numOfCars; i++) cars.add(new Car(Integer.toString(i), lot));

        for (Car c : cars) c.start();

        try {
            for (Car c : cars) c.join();
        } catch (Exception e) {
            System.out.println("ERROR: " + e.getMessage());
        }
    }
}
