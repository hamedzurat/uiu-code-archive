import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;


class Student {
    String name;
    String id;
    double cgpa;
    int    totalCreditCompleted;

    Student(String name, String id, double cgpa) {
        this.name = name;
        this.id   = id;
        this.cgpa = cgpa;
    }

    void calculateCGPA(int s1, int s2, int s3, int s4, int s5) {
        double GPA = (s1 * 4 + s2 * 4 + s3 * 4 + s4 * 4 + s5 * 4) / (5 * 4.0);

        cgpa = ((cgpa * totalCreditCompleted) + (GPA * 5)) / (totalCreditCompleted + 5);
        totalCreditCompleted += 5;
    }
}


class Window implements ActionListener, ListSelectionListener {
    private final ArrayList<Student>       students          = new ArrayList<>();
    private final JFrame                   window            = new JFrame();
    private final JPanel                   fullPanel         = new JPanel();
    private final JPanel                   leftPanel         = new JPanel();
    private final DefaultListModel<String> model             = new DefaultListModel<>();
    private final JList<String>            list              = new JList<>(model);
    private final JTextField               selectedTestField = new JTextField();
    private final JTextField               sub1TestField     = new JTextField();
    private final JTextField               sub2TestField     = new JTextField();
    private final JTextField               sub3TestField     = new JTextField();
    private final JTextField               sub4TestField     = new JTextField();
    private final JTextField               sub5TestField     = new JTextField();
    private final JButton                  selectButton      = new JButton();
    private final JButton                  calculateButton   = new JButton();
    private       Student                  selectedStudent   = null;

    {
        students.add(new Student("abrar", "1", 3.9));
        students.add(new Student("babar", "2", 2.9));
        students.add(new Student("abdur", "3", 1.1));
        students.add(new Student("shams", "4", 4));
        students.add(new Student("yeaan", "5", 3.6));
    }

    Window() {
        window.setSize(1000, 600);
        window.setTitle("CGPA calcu");
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setLocationRelativeTo(null);

        fullPanel.setLayout(new GridLayout(1, 2, 10, 10));
        leftPanel.setLayout(new BoxLayout(leftPanel, BoxLayout.Y_AXIS));

        selectedTestField.setText("Select a student first");
        selectButton.setText("Select");
        calculateButton.setText("Calculate");
        selectButton.addActionListener(this);
        calculateButton.addActionListener(this);

        leftPanel.add(new JLabel("Selected Student: "));
        leftPanel.add(selectedTestField);
        leftPanel.add(new JLabel("Input GPAs"));
        leftPanel.add(new JLabel("Subject 1"));
        leftPanel.add(sub1TestField);
        leftPanel.add(new JLabel("Subject 2"));
        leftPanel.add(sub2TestField);
        leftPanel.add(new JLabel("Subject 3"));
        leftPanel.add(sub3TestField);
        leftPanel.add(new JLabel("Subject 4"));
        leftPanel.add(sub4TestField);
        leftPanel.add(new JLabel("Subject 5"));
        leftPanel.add(sub5TestField);
        leftPanel.add(selectButton);
        leftPanel.add(calculateButton);

        list.addListSelectionListener(this);

        fullPanel.add(leftPanel);
        fullPanel.add(new JScrollPane(list));

        onUpdate();
        onUpdate();

        window.add(fullPanel);
        window.setVisible(true);
    }

    void onUpdate() {
        model.removeAllElements();

        for (int i = 0; i < students.size(); i++) {
            Student s = students.get(i);
            model.add(i, String.format("%s  |  %s  |  %.2f", s.id, s.name, s.cgpa));
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        Object src = e.getSource();

        if (src == selectButton) {
            if (selectedStudent == null) return;
            selectedTestField.setText(selectedStudent.name);
        } else if (src == calculateButton) {
            if (selectedStudent == null) return;
            try {
                int s1 = Integer.parseInt(sub1TestField.getText());
                int s2 = Integer.parseInt(sub2TestField.getText());
                int s3 = Integer.parseInt(sub3TestField.getText());
                int s4 = Integer.parseInt(sub4TestField.getText());
                int s5 = Integer.parseInt(sub5TestField.getText());

                selectedStudent.calculateCGPA(s1, s2, s3, s4, s5);
                onUpdate();
            } catch (Exception exception) {
                System.out.println("ERROR:" + exception.getMessage());
            }
        }
    }

    @Override
    public void valueChanged(ListSelectionEvent e) {
        Object src = e.getSource();

        if (src == list) {
            if (list.getSelectedIndex() >= 0) selectedStudent = students.get(list.getSelectedIndex());
        }
    }
}


public class Main {
    public static void main(String[] args) {
        new Window();
    }
}
