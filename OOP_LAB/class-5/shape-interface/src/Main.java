interface Shape {
    void printArea();
}

class Rectangle implements Shape {
    int dim1, dim2;

    public Rectangle(int d1, int d2) {
        dim1 = d1;
        dim2 = d2;
    }

    @Override
    public void printArea() {
        System.out.println(dim1 * dim2);
    }
}

class Triangle implements Shape {
    int dim1, dim2;

    public Triangle(int hight, int lenght) {
        dim1 = hight;
        dim2 = lenght;
    }

    @Override
    public void printArea() {
        System.out.println(.5 * dim1 * dim2);
    }
}

class Circle implements Shape {
    int dim1;

    public Circle(int r) {
        dim1 = r;
    }

    @Override
    public void printArea() {
        System.out.println(Math.PI * dim1 * dim1);
    }
}

public class Main {
    public static void main(String[] args) {
        Rectangle r = new Rectangle(2, 2);
        Triangle t = new Triangle(2, 2);
        Circle c = new Circle(1);

        r.printArea();
        t.printArea();
        c.printArea();
    }
}
