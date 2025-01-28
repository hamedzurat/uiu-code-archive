public class ParkingLot {
    private Integer spaces;
    private final Object mutex = new Object();

    public ParkingLot(Integer spaces) {
        this.spaces = spaces;
    }

    public boolean parkCar() {
        synchronized (mutex) {
            if (spaces > 0) {
                spaces--;
                return true;
            } else return false;
        }
    }
}
