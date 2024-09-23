import java.util.ArrayList;
import java.util.Collections;


class Book implements Comparable<Book> {
    String title;
    String author;
    double price;

    Book(String t, String a, double p) {
        title  = t;
        author = a;
        price  = p;
    }

    @Override
    public int compareTo(Book o) {
        int compared = author.compareTo(o.author);
        return (compared == 0) ? title.compareTo(o.title) : compared;
    }

    @Override
    public String toString() {
        return String.format("%s by %s. price: %f", title, author, price);
    }
}


public class Main {
    public static void main(String[] args) {
        ArrayList<Book> lib = new ArrayList<>();

        lib.add(new Book("Z", "k", 99.99));
        lib.add(new Book("B", "k", 11.11));
        lib.add(new Book("Z", "g", 5.49));
        lib.add(new Book("F", "k", 1234.78));
        lib.add(new Book("A", "x", 15));

        for (Book b : lib) System.out.println(b);

        Collections.sort(lib);
        System.out.println("-------------------------------");

        for (Book b : lib) System.out.println(b);
    }
}
