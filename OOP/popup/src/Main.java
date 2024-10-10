import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


class Window implements ActionListener {
    JFrame  frame = new JFrame();
    JButton btn   = new JButton();

    Window() {
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new FlowLayout());

        btn.setText("click");
        btn.addActionListener(this);

        frame.add(btn);

        frame.setVisible(true);
    }

    public static void main(String[] args) {
        new Window();
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        JOptionPane.showMessageDialog(frame, "Alice in OOP land");
    }
}
