import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Objects;

public class Window extends JFrame {
    private JPanel jp;
    private JTextArea list;
    private JTextPane input_name;
    private JButton calculate;
    private JLabel output;
    private JTextPane input_num;

    Window(int w, int h) {
        ArrayList<Products> products = new ArrayList<>();
        products.add(new Products("A", 10));
        products.add(new Products("B", 999));
        products.add(new Products("C", 1));
        products.add(new Products("D", 34));
        products.add(new Products("E", 789));
        products.add(new Products("F", 35));
        products.add(new Products("G", 6666));
        products.add(new Products("H", 98435));

        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        setSize(w, h);

        setLayout(null);
        setTitle("EEEEEEEEEEEEEE");
        setContentPane(jp);

        StringBuilder l = new StringBuilder();
        for (Products p : products)
            l.append(p.name).append(" -> ").append(p.price).append("\n");

        list.setText(String.valueOf(l));
        list.setEditable(false);


        calculate.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                output.setFont(output.getFont().deriveFont(24f));


                try {
                    String name = input_name.getText().trim().toUpperCase();
                    Products prod = null;
                    int num = Integer.parseInt(input_num.getText());

                    for (Products p : products)
                        if (Objects.equals(p.name, name)) prod = p;

                    if (prod != null) output.setText(String.format("%s %s is %d tk", num, prod.name, prod.price * num));
                    else output.setText("Input valid name");

                } catch (NumberFormatException ex) {
                    output.setText("Input valid number");
                }


            }
        });
    }

}

