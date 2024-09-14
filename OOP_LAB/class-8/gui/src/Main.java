import javax.swing.*;
import java.awt.event.*;

class Window extends JFrame {
    JLabel jl = new JLabel("text");
    JButton jb_click = new JButton("text");
    JButton jb_reset = new JButton("text");
    JTextField jtf = new JTextField("0");

    public Window(int w, int h) {
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        setSize(w, h);
        setLayout(null);
        setTitle("EEEEEEEEEEEEEE");

        jl.setText("clicked: ");
        jl.setBounds(10, 10, 50, 30);

        jtf.setBounds(60, 10, 100, 30);
        jtf.setEditable(false);

        jb_click.setText("click to count");
        jb_click.setBounds(10, 60, 250, 50);
        jb_click.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Integer x = Integer.parseInt(jtf.getText());
                x++;
                jtf.setText(x.toString());
            }
        });
        jb_reset.setText("reset");
        jb_reset.setBounds(280, 60, 250, 50);
        jb_reset.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                jtf.setText("0");
            }
        });

        add(jl);
        add(jb_click);
        add(jb_reset);
        add(jtf);
    }

    public String is() {
        return "Active: " + isActive() + "\tFocused: " + isFocused() + "\tVisible: " + isVisible();
    }
}

public class Main {
    public static void main(String[] args) {
        Window w = new Window(600, 200);

        while (true) {
            System.out.println(w.is());
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
