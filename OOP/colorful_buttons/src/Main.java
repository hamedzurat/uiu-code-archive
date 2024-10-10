import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


class ButtonColorChanger implements ActionListener {
    private final JFrame  frame = new JFrame();
    private final JButton btn1  = new JButton("Button 1");
    private final JButton btn2  = new JButton("Button 2");
    private       Color   clr1  = Color.RED;
    private       Color   clr2  = Color.BLUE;

    public ButtonColorChanger() {
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new FlowLayout());

        btn1.setBackground(clr1);
        btn2.setBackground(clr2);

        btn1.addActionListener(this);
        btn2.addActionListener(this);

        frame.add(btn1);
        frame.add(btn2);

        frame.setVisible(true);
    }

    public static void main(String[] args) {
        new ButtonColorChanger();
    }

    public void actionPerformed(ActionEvent e) {
        Object src = e.getSource();

        if (src == btn1) {
            if (clr1 == Color.RED) clr1 = Color.GREEN;
            else clr1 = Color.RED;

            btn1.setBackground(clr1);
        } else if (src == btn2) {
            if (clr2 == Color.BLUE) clr2 = Color.CYAN;
            else clr2 = Color.BLUE;

            btn2.setBackground(clr2);
        }
    }
}
