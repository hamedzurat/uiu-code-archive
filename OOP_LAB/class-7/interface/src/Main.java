import java.util.*;

class Student implements Comparable<Student> {
    Integer ID;
    String name;

    public Student(int ID, String name) {
        this.ID = ID;
        this.name = name;
    }

    public int compareTo(Student s) {
        System.out.println(name + " : " + s.name + " == " + (this.ID - s.ID));
        System.out.println(name + " : " + s.name + " == " + name.compareTo(s.name));

//        if (this.ID == s.ID)
//            return 0;
//        else if (this.ID > s.ID)
//            return 1;
//        else
//            return -1;

//        return Integer.compare(this.ID, s.ID);

//        return this.ID - s.ID;

//        return name.compareTo(s.name);

        if (name.compareTo(s.name) == 0)
            return ID.compareTo(s.ID) * -1;
        else
            return name.compareTo(s.name);
    }

    public String toString() {
        return ID + " : " + name;
    }
}

public class Main {
    public static void main(String[] args) {
//        ArrayList<Integer> a = new ArrayList<>();
//        a.add(1);
//        a.add(20);
//        a.add(3333);
//        a.add(4);
//
//        Collections.sort(a);
//
//        for (int i : a)
//            System.out.println(i);

//        ArrayList<String> s = new ArrayList<>();
//        s.add("zzzz");
//        s.add("a");
//        s.add("aaaaaa");
//        s.add("!zzzz");
//        s.add("  a");
//        s.add("0");
//        s.add("A");
//        s.add("Z");
//
//        Collections.sort(s);
//
//        for (String S : s)
//            System.out.println(S);

        ArrayList<Student> stu = new ArrayList<>();
        stu.add(new Student(234, "b"));
        stu.add(new Student(567, "e"));
        stu.add(new Student(456, "d"));
        stu.add(new Student(345, "a"));
        stu.add(new Student(123, "a"));

        for (Student S : stu)
            System.out.println(S.toString());

        Collections.sort(stu);

        for (Student S : stu)
            System.out.println(S.toString());
    }
}
