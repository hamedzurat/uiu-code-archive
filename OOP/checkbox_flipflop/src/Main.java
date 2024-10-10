import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;



class CheckBoxButton implements ActionListener {
    private final JFrame  frame = new JFrame();
    private final JButton button;
    private final JCheckBox checkBox;

    public CheckBoxButton() {
        frame.setLayout(new FlowLayout());

        button   = new JButton("Check");
        checkBox = new JCheckBox();

        button.addActionListener(this);

        frame.add(button);
        frame.add(checkBox);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 200);
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        new CheckBoxButton();
    }

    public void actionPerformed(ActionEvent e) {
        if (checkBox.isSelected()) {
            checkBox.setSelected(false);
            button.setText("Check");
        } else {
            checkBox.setSelected(true);
            button.setText("UnCheck");
        }
    }
}
