import java.io.*;
import java.util.*;


class EmployeeIncrement {
    public static void main(String[] args) throws IOException {
        Scanner     s  = new Scanner(System.in);
        PrintWriter ew = new PrintWriter("employee.txt");
        PrintWriter iw = new PrintWriter("increment.txt");

        int n = s.nextInt();
        s.nextLine();

        for (int i = 0; i < n; i++) {
            String name = s.nextLine();
            String id   = s.nextLine();

            double totalScore = 0;
            for (int j = 0; j < 6; j++)
                totalScore += s.nextDouble();

            s.nextLine();

            double avg = totalScore / 6;

            ew.println(name);
            ew.println(id);
            ew.println(avg);

            if (avg > 75) iw.println(name);
        }

        ew.close();
        iw.close();
        s.close();
    }
}
