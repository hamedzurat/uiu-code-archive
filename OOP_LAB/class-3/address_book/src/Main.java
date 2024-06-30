import java.util.ArrayList;

class Contact {
    int id;
    String name;
    String phone;
    String country;
    String email;

    Contact(int id, String name, String phone, String country, String email) {
        this.id = id;
        this.name = name;
        this.phone = phone;
        this.country = country;
        this.email = email;
    }

    void print() {
        System.out.println("id: " + id);
        System.out.println("name: " + name);
        System.out.println("phone: " + phone);
        System.out.println("country: " + country);
        System.out.println("email: " + email);
        System.out.println();
    }
}

class Address_book {
    ArrayList<Contact> A = new ArrayList<Contact>();
    String owner;

    Address_book(String owner) {
        this.owner = owner;
        System.out.println("Creating address book for \"" + owner + "\"");
        System.out.println();
    }

    int find_index_by_id(int id) {
        for (int i = 0; i < A.size(); i++)
            if (A.get(i).id == id) return i;

        return -1;
    }

    void add(int id, String name, String phone, String country, String email) {
        A.add(new Contact(id, name, phone, country, email));
    }

    void delete(int id) {
        int i = find_index_by_id(id);
        if (i == -1) {
            System.out.println("ERROR 404: Not Found");
            return;
        }
        A.remove(i);
    }

    void update(int id, int new_id, String name, String phone, String country, String email) {
        update_id(id, new_id);
        update_name(new_id, name);
        update_phone(new_id, phone);
        update_country(new_id, country);
        update_email(new_id, email);
    }

    void update_id(int id, int new_id) {
        int i = find_index_by_id(id);
        if (i == -1) {
            System.out.println("ERROR 404: Not Found");
            return;
        }

        A.get(i).id = new_id;
    }

    void update_name(int id, String name) {
        int i = find_index_by_id(id);
        if (i == -1) {
            System.out.println("ERROR 404: Not Found");
            return;
        }

        A.get(i).name = name;
    }

    void update_phone(int id, String phone) {
        int i = find_index_by_id(id);
        if (i == -1) {
            System.out.println("ERROR 404: Not Found");
            return;
        }

        A.get(i).phone = phone;
    }

    void update_country(int id, String country) {
        int i = find_index_by_id(id);
        if (i == -1) {
            System.out.println("ERROR 404: Not Found");
            return;
        }

        A.get(i).country = country;
    }

    void update_email(int id, String email) {
        int i = find_index_by_id(id);
        if (i == -1) {
            System.out.println("ERROR 404: Not Found");
            return;
        }

        A.get(i).email = email;
    }

    void print(int id) {
        int i = find_index_by_id(id);
        if (i == -1) {
            System.out.println("ERROR 404: Not Found");
            return;
        }

        A.get(i).print();
    }

    void print_all() {
        for (Contact contact : A)
            contact.print();
    }

    String getName(int id) {
        int i = find_index_by_id(id);
        if (i == -1) {
            System.out.println("ERROR 404: Not Found");
            return "";
        }

        return A.get(i).name;
    }

    String getPhone(int id) {
        int i = find_index_by_id(id);
        if (i == -1) {
            System.out.println("ERROR 404: Not Found");
            return "";
        }

        return A.get(i).phone;
    }

    String getCountry(int id) {
        int i = find_index_by_id(id);
        if (i == -1) {
            System.out.println("ERROR 404: Not Found");
            return "";
        }

        return A.get(i).country;
    }

    String getEmail(int id) {
        int i = find_index_by_id(id);
        if (i == -1) {
            System.out.println("ERROR 404: Not Found");
            return "";
        }

        return A.get(i).email;
    }

    String getOwner() {
        return owner;
    }

    int[] all_ids() {
        int[] ret = new int[A.size()];
        for (int i = 0; i < A.size(); i++)
            ret[i] = A.get(i).id;

        return ret;
    }

    int size() {
        return A.size();
    }

    Contact getContact(int id) {
        int i = find_index_by_id(id);
        if (i == -1) {
            System.out.println("ERROR 404: Not Found");
            return new Contact(0, "", "", "", "");
        }

        return A.get(i);
    }
}

public class Main {
    public static void main(String[] args) {

        Address_book book = new Address_book("user 1");

        book.add(135, "u1", "01555555555", "BD", "u1@protonmail.com");
        book.add(777, "u2", "01711111111", "BD", "u2@gmail.com");
        book.add(444, "u3", "+1678901234", "USA", "u3@outlook.com");

        System.out.println("-----------------------------");
        System.out.println("printing 333: ");
        System.out.println("-----------------------------");

        book.print(777);
        book.update(777, 333, "u2", "01711111111", book.getCountry(777), "u77777@gmail.com");
        book.update_name(333, "FOOBAR");
        book.update_phone(333, "017777777777");
        book.print(333);
        book.delete(333);
        book.print(333);


        System.out.println();
        System.out.println();
        System.out.println("-----------------------------");
        System.out.println("printing all: ");
        System.out.println("-----------------------------");


        book.print_all();

        System.out.println();
        System.out.println();
        System.out.println("-----------------------------");

        book.add(9999, "eee", "3745893754", "UK", "eeeeeee@gmail.com");
        book.print(9999);

        System.out.println("owner: " + book.getOwner());
        System.out.println("size: " + book.size());
        System.out.println("all contact names: ");
        int[] ids = book.all_ids();
        for (int id : ids)
            System.out.println(book.getName(id));
        for (int id : book.all_ids())
            System.out.println(book.getName(id));

        System.out.println();
        System.out.println("get full contact and display phone + email: ");
        Contact c = book.getContact(9999);
        System.out.println(c.phone);
        System.out.println(book.getContact(9999).email);
    }
}
