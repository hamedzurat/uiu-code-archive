/*

0112330113 - Hamed Zurat bin Hashem
0112330721 - Adham Zarif

*/

#include <stdio.h>
#include <string.h>

#define MAX 100

struct cricketer {
    char name[MAX];
    int age;
    int runs;
    int wickets;
    int rating;
};

struct cricketer team1[11], team2[11];


// this fucntion will return boolian based on LogIn.txt and user input
int login() {
    FILE* login_credentials = fopen("LogIn.txt", "r");

    char name[MAX], password[MAX];
    fscanf(login_credentials, "%s %s", name, password);

    fclose(login_credentials);

    char input_name[MAX], input_password[MAX];

    printf("username: ");
    scanf("%[^\n]s", input_name);
    getchar();

    printf("password: ");
    scanf("%[^\n]s", input_password);
    getchar();

    if(strcmp(name, input_name) == 0 && strcmp(password, input_password) == 0)
        return 0;

    return 1;
}

// this function takes cricketer struct as input and updates the rating variable
void calculateRating(struct cricketer* team) {
    int i;

    for(i = 0; i < 11; i++) {
        int rating = 0;
        rating += team->wickets * 8;
        if(team->runs < 20)
            rating += 4;
        else if(team->runs >= 20 && team->runs <= 50)
            rating += 12;
        else if(team->runs > 50 && team->runs <= 75)
            rating += 20;
        else
            rating += 24;

        team->rating = rating;
    }
}

// this function will display Team 1's info in the console
void displayTeam1Info() {
    printf("Team 1:\n");
    int i;
    for(i = 0; i < 11; i++) {
        printf("Name: %10s, Age: %2d, Runs: %3d, Wickets: %2d, Rating: %2d\n", team1[i].name, team1[i].age, team1[i].runs, team1[i].wickets, team1[i].rating);
    }
}

// this function will display Team 2's info in the console
void displayTeam2Info() {
    printf("Team 2:\n");
    int i;
    for(i = 0; i < 11; i++) {
        printf("Name: %10s, Age: %2d, Runs: %3d, Wickets: %2d, Rating: %2d\n", team2[i].name, team2[i].age, team2[i].runs, team2[i].wickets, team2[i].rating);
    }
}

// this fucntion will take character 'a' or 'b' based on team number
// and updated the run using user input
void updateRun(char teamChoice) {
    char playerName[MAX];
    int newRuns;

    printf("Enter player's name: ");
    scanf("%s", playerName);

    printf("Enter new runs: ");
    scanf("%d", &newRuns);

    if(teamChoice == 'a') {
        int i;
        for(i = 0; i < 11; i++) {
            if(strcmp(team1[i].name, playerName) == 0) {
                team1[i].runs = newRuns;
                calculateRating(&team1[i]);
                break;
            }
        }
    } else if(teamChoice == 'b') {
        int i;
        for(i = 0; i < 11; i++) {
            if(strcmp(team2[i].name, playerName) == 0) {
                team2[i].runs = newRuns;
                calculateRating(&team2[i]);
                break;
            }
        }
    }
}

// this fucntion will take character 'a' or 'b' based on team number and display
void youngerPlayer(char teamChoice) {
    struct cricketer youngestPlayer;

    if(teamChoice == 'a') {
        youngestPlayer = team1[0];
        int i;
        for(i = 1; i < 11; i++) {
            if(team1[i].age < youngestPlayer.age)
                youngestPlayer = team1[i];
        }
        printf("Youngest player in Team 1: %s\n", youngestPlayer.name);
    } else if(teamChoice == 'b') {
        youngestPlayer = team2[0];
        int i;
        for(i = 1; i < 11; i++) {
            if(team2[i].age < youngestPlayer.age)
                youngestPlayer = team2[i];
        }
        printf("Youngest player in Team 2: %s\n", youngestPlayer.name);
    }
}

// this function saves most rated player of team1 in the score.txt file
void mostRatedPlayerTeam1() {
    int max = 0;  // initializing with max run is 0

    for(int i = 1; i < 11; i++)
        if(team1[i].rating > team1[max].rating)
            max = i;

    FILE* score = fopen("score.txt", "a");

    fprintf(score, "%d ", max);
    printf("Index of most rated player from team1 has been saved to score.txt\n");

    fclose(score);
}

// this function saves most rated player of team2 in the score.txt file
void mostRatedPlayerTeam2() {
    int max = 0;  // initializing with max run is 0

    for(int i = 1; i < 11; i++)
        if(team2[i].rating > team2[max].rating)
            max = i;

    FILE* score = fopen("score.txt", "a");

    fprintf(score, "%d ", max);
    printf("Index of most rated player from team2 has been saved to score.txt\n");

    fclose(score);
}

// this function reads from score.txt and displays the Man of the Match
void manOfTheMatch() {
    FILE* score = fopen("score.txt", "r");
    int index1, index2;

    fscanf(score, "%d %d", &index1, &index2);

    if(team1[index1].rating > team2[index2].rating)  // calculating the overall highest rating
        printf("Man of the Match: %s from Team 1\n", team1[index1].name);
    else
        printf("Man of the Match: %s from Team 2\n", team2[index2].name);

    fclose(score);
}

int main(void) {

    printf("--- --- ---\n");
    printf("   login\n");
    printf("--- --- ---\n");

    while(login() != 0)
        printf("Invalid information.\n");

    printf("--- --- ---\n");
    printf("    menu\n");
    printf("--- --- ---\n");


    FILE* f1 = fopen("team1.txt", "r");

    for(int i = 0; i < 11; i++) {
        fscanf(f1, "%s %d %d %d", team1[i].name, &team1[i].age, &team1[i].runs, &team1[i].wickets);
        calculateRating(&team1[i]);
    }

    fclose(f1);


    FILE* f2 = fopen("team2.txt", "r");

    for(int i = 0; i < 11; i++) {
        fscanf(f2, "%s %d %d %d", team2[i].name, &team2[i].age, &team2[i].runs, &team2[i].wickets);
        calculateRating(&team2[i]);
    }

    fclose(f2);


    while(1) {
        char code;

        printf("--- --- ---\n");
        printf("code: ");
        scanf("%s", &code);

        if(code == 'q' || code == 'Q')
            break;
        else if(code == '1')
            displayTeam1Info();
        else if(code == '2')
            displayTeam2Info();
        else if(code == '3') {
            char team_num;
            printf("a = team1 & b = team2\nteamcode: ");
            scanf("%s", &team_num);
            updateRun(team_num);
        } else if(code == '4') {
            char team_num;
            printf("a = team1 & b = team2\nteamcode: ");
            scanf("%s", &team_num);
            youngerPlayer(team_num);
        } else if(code == '5')
            mostRatedPlayerTeam1();
        else if(code == '6')
            mostRatedPlayerTeam2();
        else if(code == '7')
            manOfTheMatch();
    }

    remove("score.txt");  // remove the score.txt file

    printf("--- --- ---\n");
    printf("Thank you\n");
    printf("--- --- ---\n");

    return 0;
}
