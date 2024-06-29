class Parent {
    static {
        System.out.println(" - Parent iib 2 (static)");
    }

    int n = 0, i1 = 222;

    {
        System.out.println(" - Parent iib 1");
    }

    {
        System.out.println(" - Parent iib 3");
    }

    public Parent() {
        System.out.println(" - Parent constructor (no arg)");
    }

    public Parent(int x) {
        System.out.println(" - Parent constructor (with arg)");
    }

    public static void test() {
        System.out.println(" - static func");
    }

    public void bar() {
        System.out.println("[Parent] : n = " + n + " i1 = " + i1);
    }
}

class Child extends Parent {
    int n = 999, i2 = 777;

    {
        System.out.println(" - Child iib 1");
    }

    {
        System.out.println(" - Child iib 2");
    }

    public Child() {
//        ERROR: Call to 'super()' must be first statement in constructor body
//        System.out.println(" - C constructor start");
//        super();
        System.out.println(" - Child constructor end");
    }

    public void foo(int x) {
//        ERROR: Call to 'super()' only allowed in constructor body
//        super(x);
        System.out.println(" - Child's foo method start");

        this.bar();

        System.out.println(" - changing vars: n = 456; super.n = 789; i1 = 666; i2 = 444");
        n = 456;
        super.n = 789;
        i1 = 666;
        i2 = 444;

        bar();

        System.out.println(" - Child's foo method end");
    }

    public void bar() {
        System.out.println("[ Child] : n = " + n + " i1 = " + i1 + " i2 = " + i2);
        super.bar();
    }
}

class Exe {
    static {
        System.out.println(" - exe iib (static)");
    }

    {
        System.out.println(" - exe iib");
    }

    public Exe() {
        System.out.println(" - exe constructor");
    }

    public static void run() {
        System.out.println(" - exe run");
    }

    public void walk() {
        System.out.println(" - exe walk");
    }
}

public class Main {
    static {
        System.out.println(" - Main iib (static)");
    }

    {
        System.out.println(" - Main iib");
    }

    public Main() {
        System.out.println(" - Main constructor");
    }

    public static void main(String[] args) {
        System.out.println(" - Main method start");

        Child z = new Child();
        z.foo(12);
        Parent.test();

        System.out.println(" : Exe.run();");
        Exe.run();
        System.out.println(" : Exe e =  new Exe();");
        Exe e = new Exe();
        System.out.println(" : e.walk();");
        e.walk();
        System.out.println(" : Exe.run();");
        Exe.run();

        System.out.println(" - Main method end");
    }
}
