public class Car extends Thread {
    private final String name;
    private final ParkingLot lot;
    public static int timeout = 15000;

    public Car(String name, ParkingLot lot) {
        this.name = name;
        this.lot = lot;
    }

    @Override
    public void run() {
        int time = 0;
        while (!lot.parkCar()) {
            try {
                System.out.println(name + " is waiting for parking space for " + (double)time / 1000 + "s.");

                Thread.sleep(3500);
                time += 3500;

                if (time > timeout) {
                    System.out.println(name + " gave up.");
                    return;
                }
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
        System.out.println(name + " got a parking space.");
    }
}
