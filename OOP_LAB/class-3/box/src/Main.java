class Box {
    int lenght, width, hight;

    Box(int lenght, int width, int hight) {
        this.lenght = lenght;
        this.width = width;
        this.hight = hight;
    }

    int getVolume() {
        return lenght * width * hight;
    }
}

public class Main {
    public static void main(String[] args) {
        Box b1 = new Box(1, 1, 1);
        System.out.println(b1.getVolume());
        Box b2 = new Box(7, 8, 9);
        System.out.println(b2.getVolume());
    }
}
