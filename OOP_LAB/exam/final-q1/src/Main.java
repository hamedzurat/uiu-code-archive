class BuildingException extends Exception {
    BuildingException(String msg) {
        super("[BuildingException] " + msg);
    }
}


class Building {
    private int   id;
    private int   noOfFloors;
    private int   floorSize;
    private int   noOfUnits;
    private float perSquareFeetPrice;

    Building() {}

    Building(int floorSize, int noOfFloors, int noOfUnits) throws BuildingException {
        if (noOfFloors < 5) throw new BuildingException("Not enough floors!");
        if (noOfUnits < 2) throw new BuildingException("Not enough units!");
        if (floorSize < 1800) throw new BuildingException("Not bit enough!");

        this.floorSize  = floorSize;
        this.noOfFloors = noOfFloors;
        this.noOfUnits  = noOfUnits;
    }
}


public class Main {
    public static void main(String[] args) {
        try {
            new Building(1800, 6, 1);
        } catch (BuildingException e) {
            System.out.println("ERROR: " + e.getMessage());
        }
    }
}
