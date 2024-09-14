import java.util.*;

class Player implements Comparable<Player> {
    String name;
    Integer score;

    public Player(String name, Integer score) {
        this.name = name;
        this.score = score;
    }

    public int compareTo(Player p) {
        if (score.compareTo(p.score) == 0)
            return name.compareTo(p.name);
        else
            return score.compareTo(p.score) * -1;
    }

    public String toString() {
        return name + " : " + score;
    }
}

public class Main {
    public static void main(String[] args) {
        ArrayList<Player> p = new ArrayList<>();

        Scanner s = new Scanner(System.in);

        for (int i = 0; i < 5; i++) {
            String name = s.next();
            int score = s.nextInt();

            p.add(new Player(name, score));
        }
        s.close();

        Collections.sort(p);

        for (Player P : p)
            System.out.println(P.toString());
    }
}

//amy 100
//david 100
//heraldo 50
//aakansha 75
//alek 150
