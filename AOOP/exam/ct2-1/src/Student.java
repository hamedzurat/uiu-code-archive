import java.io.Serializable;


public class Student implements Comparable<Student>, Serializable {
    private final String  name;
    private final Integer ID;
    private final Double  CGPA;

    public Student(String name, Integer ID, Double CGPA) {
        this.name = name;
        this.ID   = ID;
        this.CGPA = CGPA;
    }

    @Override
    public String toString() {
        return "Student{"
               + "name='" + name + "'"
               + ", ID=" + ID
               + ", CGPA=" + CGPA
               + '}';
    }

    public String getName() {return name;}

    public Integer getID()  {return ID;}

    @Override
    public int compareTo(Student o) {
        return this.getID().compareTo(o.getID());

//        if (this.getID() > o.getID()) return 1;
//        else if (this.getID() < o.getID()) return -1;
//        else return 0;
    }
}
