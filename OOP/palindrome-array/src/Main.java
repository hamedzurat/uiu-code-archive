import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int size = scan.nextInt();
        int[] array = new int[size];

        for (int i = 0; i < size; i++) {
            array[i] = scan.nextInt();
        }

        boolean palindrom = true;
        for (int i = 0; i < size; i++)
            if (array[i] != array[size - i - 1])
                palindrom = false;

        if (palindrom)
            System.out.println("Yes");
        else
            System.out.println("No");

        scan.close();
    }
}
