import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;


public class Main {
    public static void main(String[] args) {
        new Window(500, 300);
    }
}


class Product {
    private final int    id;
    private final String name;
    private final double price;
    private       int    quantity;

    Product(int id, String name, double price, int quantity) {
        this.id       = id;
        this.name     = name;
        this.price    = price;
        this.quantity = quantity;
    }

    public int getId() {
        return id;
    }

    public double getPrice() {
        return price;
    }

    public int getQuantity() {
        return quantity;
    }

    public String getName() {
        return name;
    }

    public void buy(int quantity) {
        if (getQuantity() - quantity < 0) throw new IllegalStateException("We don't have that many item");
        else this.quantity -= quantity;
    }
}


class ProductInCart {
    private final Product p;
    private       int     quantity;

    ProductInCart(Product p, int quantity) {
        this.p        = p;
        this.quantity = quantity;
    }

    public int getId() {
        return p.getId();
    }

    public String getName() {
        return p.getName();
    }

    public int getQuantity() {
        return quantity;
    }

    public void setQuantity(int x) {
        quantity = x;
    }

    public double getCost() {
        // https://stackoverflow.com/questions/11701399/round-up-to-2-decimal-places-in-java
        return Double.parseDouble(String.format("%.2f", getQuantity() * p.getPrice()));
    }
}


class Window implements ListSelectionListener, ActionListener {
    private static final int                      PAD               = 10;
    private static final Color                    BG                = Color.lightGray;
    private static final Color                    FG                = Color.white;
    private static       Product                  SELECTION_OF_ALL  = null;
    private static       ProductInCart            SELECTION_OF_CART = null;
    private final        JFrame                   window            = new JFrame();
    private final        JPanel                   thePanel          = new JPanel();
    private final        JPanel                   topPanel          = new JPanel();
    private final        JPanel                   leftPanel         = new JPanel();
    private final        JPanel                   rightPanel        = new JPanel();
    private final        JPanel                   bottomPanel       = new JPanel();
    private final        JPanel                   col1Panel         = new JPanel();
    private final        JPanel                   col2Panel         = new JPanel();
    private final        JPanel                   col3Panel         = new JPanel();
    private final        JButton                  removeButton      = new JButton();
    private final        JButton                  doneButton        = new JButton();
    private final        JButton                  buyButton         = new JButton();
    private final        JTextField               selectedTextField = new JTextField();
    private final        JTextField               quantityTextField = new JTextField();
    private final        JTextArea                summaryTextArea   = new JTextArea();
    private final        ArrayList<Product>       ALL               = new ArrayList<>();
    private final        DefaultTableModel        allModel          = new DefaultTableModel(new String[]{"ID", "Product Name", "Price", "Quantity"}, 0);
    private final        JTable                   availableTable    = new JTable(allModel);
    private final        ArrayList<ProductInCart> CART              = new ArrayList<>();
    private final        DefaultTableModel        cartModel         = new DefaultTableModel(new String[]{"ID", "Product Name", "Quantity Added", "Total Price"}, 0);
    private final        JTable                   cartTable         = new JTable(cartModel);

    // populate product list
    {
        ALL.add(new Product(1, "Laptop", 999.99, 10));
        ALL.add(new Product(2, "Smartphone", 599.99, 15));
        ALL.add(new Product(3, "Headphones", 49.99, 30));
        ALL.add(new Product(4, "Smartwatch", 199.99, 20));
        ALL.add(new Product(5, "Tablet", 399.99, 8));
        ALL.add(new Product(6, "Camera", 699.99, 5));
        ALL.add(new Product(7, "Bluetooth Speaker", 89.99, 25));
        ALL.add(new Product(8, "Wireless Mouse", 29.99, 50));
        ALL.add(new Product(9, "Mechanical Keyboard", 79.99, 40));
        ALL.add(new Product(10, "Gaming Console", 499.99, 12));
        ALL.add(new Product(11, "External Hard Drive", 89.99, 18));
        ALL.add(new Product(12, "Monitor", 249.99, 7));
        ALL.add(new Product(13, "Fitness Tracker", 149.99, 22));
        ALL.add(new Product(14, "Electric Kettle", 39.99, 30));
        ALL.add(new Product(15, "Coffee Machine", 129.99, 9));
        ALL.add(new Product(16, "Air Purifier", 199.99, 14));
        ALL.add(new Product(17, "Vacuum Cleaner", 149.99, 10));
        ALL.add(new Product(18, "Smart TV", 1099.99, 6));
        ALL.add(new Product(19, "Gaming Chair", 229.99, 13));
        ALL.add(new Product(20, "Drone", 899.99, 4));
    }

    Window(int x, int y) {
        window.setSize(x, y);
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setLocationRelativeTo(null);
        window.setTitle("Not Amazon");

        // add padding to make it look good
        for (JPanel p : new JPanel[]{thePanel, bottomPanel, leftPanel, rightPanel}) p.setBorder(new EmptyBorder(PAD, PAD, PAD, PAD));

        // setting all layouts
        thePanel.setLayout(new BorderLayout(PAD, PAD));
        topPanel.setLayout(new GridLayout(1, 2, PAD, PAD));
        leftPanel.setLayout(new BorderLayout(PAD, PAD));
        rightPanel.setLayout(new BorderLayout(PAD, PAD));
        bottomPanel.setLayout(new BorderLayout(PAD, PAD));
        col1Panel.setLayout(new GridLayout(3, 1, PAD, PAD));
        col2Panel.setLayout(new BoxLayout(col2Panel, BoxLayout.Y_AXIS));
        col3Panel.setLayout(new GridLayout(3, 1, PAD, PAD));

        // setting colors
        for (JPanel p : new JPanel[]{thePanel, topPanel}) p.setBackground(BG);
        for (JPanel p : new JPanel[]{bottomPanel, leftPanel, rightPanel}) p.setBackground(FG);

        // populating table from the arraylist
        onAnyUpdate();

        // disabling editing
        // https://stackoverflow.com/questions/9919230/disable-user-edit-in-jtable
        availableTable.setDefaultEditor(Object.class, null);
        cartTable.setDefaultEditor(Object.class, null);

        // making ID column 40px wide
        // https://stackoverflow.com/questions/953972/java-jtable-setting-column-width
        availableTable.getColumnModel().getColumn(0).setMaxWidth(40);
        cartTable.getColumnModel().getColumn(0).setMaxWidth(40);

        // https://stackoverflow.com/questions/18309113/jtable-how-to-force-user-to-select-exactly-one-row
        availableTable.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        cartTable.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);

        // setting jtable's event handler
        availableTable.getSelectionModel().addListSelectionListener(this);
        cartTable.getSelectionModel().addListSelectionListener(this);

        // adding elements to topPanel
        leftPanel.add(new JLabel("Available Products:"), BorderLayout.NORTH);
        rightPanel.add(new JLabel("In Cart:"), BorderLayout.NORTH);
        leftPanel.add(new JScrollPane(availableTable), BorderLayout.CENTER);
        rightPanel.add(new JScrollPane(cartTable), BorderLayout.CENTER);

        topPanel.add(leftPanel);
        topPanel.add(rightPanel);

        // buttons
        removeButton.setText("Remove");
        doneButton.setText("Done");
        buyButton.setText("Buy");

        removeButton.addActionListener(this);
        doneButton.addActionListener(this);
        buyButton.addActionListener(this);

        // dont let the user edit those two
        selectedTextField.setEditable(false);
        summaryTextArea.setEditable(false);

        // adding all elements to bottomPanel
        col1Panel.add(new JLabel("Selected:"));
        col2Panel.add(selectedTextField);
        col2Panel.add(Box.createRigidArea(new Dimension(0, PAD)));
        col3Panel.add(removeButton);

        col1Panel.add(new JLabel("Quantity:"));
        col2Panel.add(quantityTextField);
        col2Panel.add(Box.createRigidArea(new Dimension(0, PAD)));
        col3Panel.add(doneButton);

        col1Panel.add(new JLabel("Order Summary:"));
        col2Panel.add(summaryTextArea);
        col3Panel.add(buyButton);

        bottomPanel.add(col1Panel, BorderLayout.WEST);
        bottomPanel.add(col2Panel, BorderLayout.CENTER);
        bottomPanel.add(col3Panel, BorderLayout.EAST);

        thePanel.add(topPanel, BorderLayout.CENTER);
        thePanel.add(bottomPanel, BorderLayout.SOUTH);

        window.add(thePanel);
        window.setVisible(true);
    }

    // run this function after editing the arraylists, or any of its elements.
    // if you dont, the table wont be updated
    // ¯\_(ツ)_/¯
    private void onAnyUpdate() {
        // remove existing rows before adding again from the list
        // https://stackoverflow.com/questions/10413977/removing-all-the-rows-of-defaulttablemodel
        allModel.setRowCount(0);
        cartModel.setRowCount(0);
        for (Product i : ALL) allModel.addRow(new Object[]{i.getId(), i.getName(), i.getPrice(), i.getQuantity()});
        for (ProductInCart i : CART) cartModel.addRow(new Object[]{i.getId(), i.getName(), i.getQuantity(), i.getCost()});

        StringBuilder listOfItem    = new StringBuilder();
        int           totalQuantity = 0;
        double        totalAmount   = 0;

        for (int i = 0; i < CART.size(); i++) {
            ProductInCart p = CART.get(i);
            listOfItem.append(p.getName());

            if (i < CART.size() - 1) listOfItem.append(", ");

            totalQuantity += p.getQuantity();
            totalAmount += p.getCost();
        }

        String summary;

        if (CART.isEmpty()) summary = "Add some item to cart";
        else summary = String.format("List of items: %s\nTotal Quantity: %d\nTotal Payable Amount: %.2f", listOfItem, totalQuantity, totalAmount);

        summaryTextArea.setText(summary);
    }

    private int getIndexById(String type, int id) {
        if (type.equals("all")) {
            for (int i = 0; i < ALL.size(); i++)
                if (ALL.get(i).getId() == id) return i;
        } else if (type.equals("cart")) {
            for (int i = 0; i < CART.size(); i++)
                if (CART.get(i).getId() == id) return i;
        }

        return -1;
    }

    @Override
    public void valueChanged(ListSelectionEvent e) {
        // no duplicate event firing
        // https://stackoverflow.com/questions/10860419/what-exactly-does-getvalueisadjusting-do
        if (e.getValueIsAdjusting()) return;

        Object src          = e.getSource();
        JTable focusedTable = null;
        JTable otherTable   = null;
        String type         = null;

        if (src == availableTable.getSelectionModel()) {
            type         = "all";
            focusedTable = availableTable;
            otherTable   = cartTable;
        } else if (src == cartTable.getSelectionModel()) {
            type         = "cart";
            focusedTable = cartTable;
            otherTable   = availableTable;
        }

        if (type != null) {
            int selectedRow = focusedTable.getSelectedRow();
            if (selectedRow != -1) {
                int id = Integer.parseInt(focusedTable.getValueAt(selectedRow, 0).toString());

                int allIndex  = getIndexById("all", id);
                int cartIndex = getIndexById("cart", id);

                if (type.equals("all")) {
                    SELECTION_OF_ALL  = ALL.get(allIndex);
                    SELECTION_OF_CART = null;
                    selectedTextField.setText(SELECTION_OF_ALL.getName());
                } else if (type.equals("cart")) {
                    SELECTION_OF_ALL  = null;
                    SELECTION_OF_CART = CART.get(cartIndex);
                    selectedTextField.setText(SELECTION_OF_CART.getName());
                }

                // clear other table's selection
                // https://stackoverflow.com/questions/18337580/jtable-clearselection-vs-jtable-getselectionmodel-clearselection-when-to-u
                otherTable.getSelectionModel().clearSelection();

                // reset the quantity field
                quantityTextField.setText("0");
            }
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        Object src = e.getSource();

        if (src == removeButton) {
            int indexOfALL  = -1;
            int indexOfCART = -1;

            if (SELECTION_OF_ALL != null) {
                indexOfALL  = getIndexById("all", SELECTION_OF_ALL.getId());
                indexOfCART = getIndexById("cart", SELECTION_OF_ALL.getId());
            } else if (SELECTION_OF_CART != null) {
                indexOfCART = getIndexById("cart", SELECTION_OF_CART.getId());
            }

            if (indexOfALL != -1) ALL.remove(indexOfALL);
            if (indexOfCART != -1) CART.remove(indexOfCART);

            quantityTextField.setText("");
            selectedTextField.setText("");

            onAnyUpdate();
        } else if (src == doneButton) {
            try {
                if (SELECTION_OF_ALL == null) return;

                int quantity = Integer.parseInt(quantityTextField.getText());
                if (quantity == 0) return;

                SELECTION_OF_ALL.buy(quantity);

                boolean alreadyInTheCart = false;
                for (ProductInCart p : CART) {
                    if (p.getId() == SELECTION_OF_ALL.getId()) {
                        p.setQuantity(p.getQuantity() + quantity);
                        alreadyInTheCart = true;
                        break;
                    }
                }
                if (!alreadyInTheCart) {
                    CART.add(new ProductInCart(SELECTION_OF_ALL, quantity));
                }
            } catch (NumberFormatException exception) {
                quantityTextField.setText("0");
                System.out.println(exception.getMessage());
                JOptionPane.showMessageDialog(window, "ERROR: Failed to parse " + exception.getMessage());
            } catch (IllegalStateException exception) {
                quantityTextField.setText("0");
                System.out.println(exception.getMessage());
                JOptionPane.showMessageDialog(window, "ERROR: " + exception.getMessage());
            } finally {
                onAnyUpdate();
            }
        } else if (src == buyButton) {
            JOptionPane.showMessageDialog(window, "Thanks for the purchase.");
        }
    }
}
