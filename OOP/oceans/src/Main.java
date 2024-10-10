import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


class Window {
    JFrame f = new JFrame();

    Window() {
        f.setSize(300, 150);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setLayout(new FlowLayout());

        String[] oceans = {"Arctic", "North Atlantic", "South Atlantic", "Indian", "North Pacific", "South Pacific", "Antarctic"};

        JTextField tf1        = new JTextField(20);
        JTextField tf2        = new JTextField(20);
        JButton    showButton = new JButton("Show");

        f.add(tf1);
        f.add(tf2);
        f.add(showButton);

        showButton.addActionListener(e -> tf2.setText(oceans[Integer.parseInt(tf1.getText())]));

        f.setVisible(true);
    }
}


public class Main {
    public static void main(String[] args) {
        new Window();
    }
}

