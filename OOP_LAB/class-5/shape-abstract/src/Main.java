abstract class Shape {
    static {
        System.out.println("static iib");
    }

    int dim1, dim2;

    {
        System.out.println("iib");
    }

    Shape(int in1, int in2) {
        dim1 = in1;
        dim2 = in2;
    }

    abstract void printArea();
}

class Rectangle extends Shape {
    public Rectangle(int d1, int d2) {
        super(d1, d2);
    }

    @Override
    void printArea() {
        System.out.println(dim1 * dim2);
    }
}

class Triangle extends Shape {
    public Triangle(int hight, int lenght) {
        super(hight, lenght);
    }

    @Override
    void printArea() {
        System.out.println(.5 * dim1 * dim2);
    }
}

class Circle extends Shape {
    public Circle(int r) {
        super(r, 0);
    }

    @Override
    void printArea() {
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
