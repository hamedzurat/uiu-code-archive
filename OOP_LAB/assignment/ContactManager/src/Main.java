import java.util.*;

class Contact {
    private String name;
    private String address;
    private String phone;

    public Contact(String name, String address, String phone) {
        this.name = name;
        this.address = address;
        this.phone = phone;
    }

    public boolean isName(String name) {
        return this.name.matches(name);
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public String print() {
        return "Name: " + name + ", Address: " + address + ", Phone: " + phone;
    }
}

class AddressBook {
    static Scanner scanner = new Scanner(System.in);
    private ArrayList<Contact> book = new ArrayList<>();

    public void addContact() {
        String name;
        String address;
        String phone;

        System.out.print("Enter Name: ");
        name = scanner.nextLine();

        if (findContactByName(name) == null) {
            System.out.print("Enter Address: ");
            address = scanner.nextLine();
            System.out.print("Enter Phone Number: ");
            phone = scanner.nextLine();

            book.add(new Contact(name, address, phone));

            System.out.println("done.");
        } else {
            System.out.print("ERROR: Contact exists with this name.");
        }

    }

    public void updateContact() {

        System.out.print("Enter the name of the contact to update: ");
        Contact contact = findContactByName(scanner.nextLine());

        if (contact != null) {
            System.out.print("Enter new Address: ");
            contact.setAddress(scanner.nextLine());
            System.out.print("Enter new Phone Number: ");
            contact.setPhone(scanner.nextLine());

            System.out.print("done.");
        } else {
            System.out.print("ERROR: Contact not found.");
        }
    }

    public void deleteContact() {
        System.out.print("Enter the name of the contact to delete: ");
        Contact contact = findContactByName(scanner.nextLine());

        if (contact != null) {
            book.remove(contact);
            System.out.println("done.");
        } else {
            System.out.print("ERROR: Contact not found.");
        }
    }

    public void displayContacts() {
        if (book.isEmpty()) {
            System.out.println("ERROR: Add contacts first.");
        } else {
            System.out.println("Contacts:");
            for (Contact contact : book) {
                System.out.println(contact.print());
            }
        }
    }

    public Contact findContactByName(String name) {
        for (Contact contact : book) {
            if (contact.isName(name)) {
                return contact;
            }
        }
        return null;
    }
}

public class Main {
    static void printMenu() {
        System.out.println();
        System.out.println("MENU:");
        System.out.println("------");
        System.out.println("1: Add Contact");
        System.out.println("2: Update Contact");
        System.out.println("3: Delete Contact");
        System.out.println("4: View Contacts");
        System.out.println("5: Exit");
        System.out.print("Enter: ");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        AddressBook contacts = new AddressBook();

        for (int i = 0; i < 5; i++) {
            System.out.println("Enter Contact info of " + (i + 1));
            contacts.addContact();
        }

        while (true) {
            Main.printMenu();

            switch (scanner.nextInt()) {
                case 1 -> contacts.addContact();
                case 2 -> contacts.updateContact();
                case 3 -> contacts.deleteContact();
                case 4 -> contacts.displayContacts();
                case 5 -> {
                    return;
                }
                default -> System.out.println("ERROR: Command not found.");
            }
            scanner.nextLine();
        }
    }
}
