import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


class TemperatureConverter implements ActionListener {
    private final JFrame     frame = new JFrame();
    private final JTextField txtC  = new JTextField();
    private final JTextField txtF  = new JTextField();
    private final JLabel     lC    = new JLabel("Celsius: ");
    private final JLabel     lF    = new JLabel("Fahrenheit: ");
    private final JButton    btn   = new JButton("Convert");

    public TemperatureConverter() {
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(5, 1));

        txtF.setEditable(false);

        btn.addActionListener(this);

        frame.add(lC);
        frame.add(txtC);
        frame.add(lF);
        frame.add(txtF);
        frame.add(btn);

        frame.setVisible(true);
    }

    public static void main(String[] args) {
        new TemperatureConverter();
    }

    public void actionPerformed(ActionEvent e) {
        double c    = Double.parseDouble(txtC.getText());
        double f = (c * 9 / 5) + 32;
        txtF.setText(String.valueOf(f));
    }
}
