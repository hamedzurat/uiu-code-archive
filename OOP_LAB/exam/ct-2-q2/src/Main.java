abstract class Animal {
    int legs;

    Animal(int l) {
        this.legs = l;
    }

    abstract void eat();

    void walk() {
        System.out.printf("Walks with %s %s\n", this.legs, ((legs == 1) ? "leg" : "legs"));
    }
}


class Spider extends Animal {
    Spider() {
        super(8);
    }

    void eat() {
        System.out.println("Eating bugs");
    }
}


public class Main {
    public static void main(String[] args) {
        Spider s = new Spider();

        s.walk();
        s.eat();
    }
}
