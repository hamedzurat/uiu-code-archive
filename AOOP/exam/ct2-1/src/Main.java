import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Collections;


public class Main {
    public static final String FILE_NAME = "StudentData.txt";

    public static void main(String[] args) {
        Student s1 = new Student("KKKK", 4, 4.0);
        Student s2 = new Student("ZZZZ", 2, 3.0);
        Student s3 = new Student("FFFF", 3, 1.67);
        Student s4 = new Student("LLLL", 1, 2.0);
        Student s5 = new Student("BBBB", 5, 3.33);

        ArrayList<Student> section = new ArrayList<>();
        section.add(s1);
        section.add(s2);
        section.add(s3);
        section.add(s4);
        section.add(s5);

        System.out.println("Before anything:  " + section);
        Collections.sort(section);
        System.out.println("After Comparable: " + section);
        Collections.sort(section, new NameComparator());
        System.out.println("After Comparator: " + section);

        try {
            ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(FILE_NAME));

            oos.writeObject(s1);
            oos.writeObject(s2);
            oos.writeObject(s3);
            oos.writeObject(s4);
            oos.writeObject(s5);

            oos.flush();
            oos.close();
        } catch (Exception e) {
            System.out.println("ERROR while writing: " + e.getMessage());
        }

        Student ns1, ns2, ns3, ns4, ns5;

        try {
            ObjectInputStream ois = new ObjectInputStream(new FileInputStream(FILE_NAME));

            ns1 = (Student) ois.readObject();
            ns2 = (Student) ois.readObject();
            ns3 = (Student) ois.readObject();
            ns4 = (Student) ois.readObject();
            ns5 = (Student) ois.readObject();

            ois.close();

            System.out.println(ns1);
            System.out.println(ns2);
            System.out.println(ns3);
            System.out.println(ns4);
            System.out.println(ns5);
        } catch (Exception e) {
            System.out.println("ERROR while reading: " + e.getMessage());
        }
    }
}
